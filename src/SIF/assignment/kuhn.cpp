//////////////////////////////////////////////////////////////////////////////
//
// <kuhn.cpp>
// Copyright (C), 2013
//
// Adeline Bailly, Alexandre Quemy
//
// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  ue,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info".
//
// In this respect, the user's attention is drawn to the risks associated
// with loading,  using,  modifying and/or developing or reproducing the
// software by the user in light of its specific status of free software,
// that may mean  that it is complicated to manipulate,  and  that  also
// therefore means  that it is reserved for developers  and  experienced
// professionals having in-depth computer knowledge. Users are therefore
// encouraged to load and test the software's suitability as regards their
// requirements in conditions enabling the security of their systems and/or
// data to be ensured and,  more generally, to use and operate it in the
// same conditions as regards security.
// The fact that you are presently reading this means that you have had
// knowledge of the CeCILL license and that you accept its terms.
// 
//////////////////////////////////////////////////////////////////////////////

#include "SIF/assignment/kuhn.hpp"
#include <string>

namespace sif
{

	std::map<AResource*,ATaskSpot*> Kuhn::operator()(std::map<std::pair<AResource*, ATaskSpot*>, int> _mymap)
    {
        logger(Logger::INFO) << "Khun algorithm !";
        
		std::vector<AResource*> _resources;
		std::vector<ATaskSpot*> _taskSpots;
	
		// Step 1 : List of Resource & TaskSpot
		for (auto& eval : _mymap)
		{
			if (std::find(_resources.begin(), _resources.end(), eval.first.first) == _resources.end())
			{  	// Recovery of resources
				_resources.push_back(eval.first.first);
			}
			
			if (std::find(_taskSpots.begin(), _taskSpots.end(), eval.first.second) == _taskSpots.end())
			{	// Recovery of taskSpots
				_taskSpots.push_back(eval.first.second);
			}
		
		}
		// Step 2 : Creation of square matrix
		int sizeResources = _resources.size(), sizeTaskSpots = _taskSpots.size();
		if (sizeResources > sizeTaskSpots)
		{
			for (int i=0; i<sizeResources - sizeTaskSpots; i++)
				_taskSpots.push_back(nullptr);
		}
		else if (sizeResources < sizeTaskSpots)
		{
			for (int i=0; i<sizeTaskSpots - sizeResources; i++)
				_resources.push_back(nullptr);
		}
		// Cost Matrix
		cost.resize(_resources.size());
		for (int i=0; i<_resources.size(); i++)
		{
			cost[i].resize(_taskSpots.size());
			for (int j=0; j<_taskSpots.size(); j++)
				cost[i][j] = -1;
		}

		for (auto& eval : _mymap)
		{
			bool find = false;
			int indR = 0, indTS = 0;
			while (indR < _resources.size() && !find)
			{
			    
				if (eval.first.first == _resources[indR])
					find = true;
				else
				    indR++;
			}
			find = false;
			while (indTS< _taskSpots.size() && !find)
			{
				if (eval.first.second == _taskSpots[indTS])
					find = true;
			    else
				    indTS++;
			}
			cost[indR][indTS] = eval.second;
		}
		
		for (int i=0; i<cost.size(); i++)
		{
			for (int j=0; j<cost.size(); j++)
				if (cost[i][j] == -1)
					cost[i][j] = INT_MAX;
		}
		
		// Algorithm : Kuhn */
		int n = _resources.size();
		typeMat mat(n);
		for (int i=0; i<n; i++)
		{
			mat[i].resize(n);
			for (int j=0; j<n; j++)
			{
				mat[i][j].first = cost[i][j];
				mat[i][j].second = Normal;
			}
		}
		subtractionMins(mat);
		
		int line;
		bool b, isPossible, repeat = true, exception = false;
		std::vector<bool> markedLines(n), markedRows(n);
		int compteur = 0;
		do
		{
			// Clean
			for (int i=0; i<n; i++)
			{
				markedLines[i] = false;
				markedRows[i] = false;
				for (int j=0; j<n; j++)
					mat[i][j].second = Normal;
			}
			// 2- Encadrer et barrer les zéros
			isPossible = true;
			while (isPossible)
			{
			    
				int i = 0;
				line = lineWLessZUncrossed (mat);
				if (line != -1)
				{
					b = false;
					if (!exception)
					{
						while (!b)
						{
							if (mat[line][i].first == 0)
							{
								if (!ZSurrondSameCol(mat, i))
								{
									mat[line][i].second = Surrounded;
									b = true;
								}
							}
							i++;
						}
					i--;
					}
					else // cas exception
					{
						//logger(Logger::INFO) << "Exception !";
						i = mat.size() -1;
						while (!b)
						{
							if (mat[line][i].first == 0)
							{
								if (!ZSurrondSameCol(mat, i))
								{
									mat[line][i].second = Surrounded;
									b = true;
								}
							}
							i--;
						}
					i++;
					}
					strikeZLocatedSameArea(mat, line, i);
				}
				else
					isPossible = false;
			}
			
			if (!zeroOnAllRC(mat))
			{
				markLinesInit(mat, markedLines);
				bool _continue = true;
				while (_continue)
				{
					_continue = markRows(mat, markedLines, markedRows);
					if (_continue)
						_continue = markLines(mat, markedLines, markedRows);
				}
				exception = isFullmarked(markedLines, markedRows);
				/*-
				logger(Logger::INFO) << " - ";
				for (int i=0; i<n; i++)
				{
					std::string msg;
					for (int j=0; j<n ; j++)
					{
						msg += std::to_string(mat[i][j].first) + " ";
					}
					logger(Logger::INFO) << msg;
				}
				logger(Logger::INFO) << " - ";
				for (int i=0; i<n; i++)
				{
					std::string msg;
					for (int j=0; j<n ; j++)
					{
						msg += std::to_string(mat[i][j].second) + " ";
					}
					logger(Logger::INFO) << msg;
				}//-*/
				subtractionPartTable(mat, markedLines, markedRows);
			}
			else
				repeat = false;
			
		} while (repeat);
		
		std::map<AResource*,ATaskSpot*> assignment;
		int i = 0, j;
		while(i < n)
		{
			bool find = false;
			j = 0;
			while(j < n && find == false)
			{
				if (mat[i][j].second == Surrounded)
				{
					if (_resources[i] != nullptr && _taskSpots[j] != nullptr)
						assignment.insert(std::pair<AResource*,ATaskSpot*> (_resources[i], _taskSpots[j]));
					find = true;
				}
				j++;
			}
			i++;
		}
		
		logger(Logger::PROGRESS) << "END Khun algorithm !";

		return assignment;
    }

	// --------------------------------------------------------------------
	// --------------------------------------------------------------------
	
	bool Kuhn::isFullmarked(std::vector<bool> & mdL, std::vector<bool> & mdR)
	{
		bool b = true;
		int i = 0;
		while(b && i<mdL.size())
		{
			if (mdL[i] == 0 || mdR[i] == 0)
				b = false;
			i++;
		}
		
		return b;
	}
		
	// --------------------------------------------------------------------
	
	void Kuhn::subtractionMins(typeMat & mat)
	{
		double min = INT_MAX;
		for (int i=0; i<mat.size(); i++)
		{
			for (int j=0; j<mat.size(); j++)
			{
				if (min > mat[i][j].first)
					min = mat[i][j].first;
			}
			for (int j=0; j<mat.size(); j++)
			{
				mat[i][j].first -= min;
			}
			min = INT_MAX;
		}
	
		for (int i=0; i<mat.size(); i++)
		{
			for (int j=0; j<mat.size(); j++)
			{
				if (min > mat[j][i].first)
					min = mat[j][i].first;
			}
			for (int j=0; j<mat.size(); j++)
			{
				mat[j][i].first -= min;
			}
			min = INT_MAX;
		}
	}

	// --------------------------------------------------------------------

	int Kuhn::lineWLessZUncrossed (typeMat & m)
	{
		int line = -1, counterLine = INT_MAX, counter;
	
		for (int i=0; i<m.size(); i++)
		{
			counter = 0;
			for (int j=0; j<m.size(); j++)
			{
				if (m[i][j].first == 0 && m[i][j].second == Normal)
					counter++;
			}
			if (counterLine > counter && counter != 0)
			{
				line = i;
				counterLine = counter;
			}
		}
	
		return line;
	}

	// --------------------------------------------------------------------
	bool Kuhn::ZSurrondSameCol(typeMat & m, int c)
	{
		bool b = false;
		for (int i=0; i<m.size(); i++)
		{
			if (m[i][c].second == Surrounded)
				b = true;
		}
		
		return b;
	}
	
	// --------------------------------------------------------------------
	void Kuhn::strikeZLocatedSameArea(typeMat & m, int l, int c)
	{
		for (int i=0; i<m.size(); i++)
		{
			if (m[l][i].first == 0 && i != c)
				m[l][i].second = Crossed;
			if (m[i][c].first ==0 && i != l)
				m[i][c].second = Crossed;
		}
	}

	// --------------------------------------------------------------------

	bool Kuhn::zeroOnAllRC(typeMat & m)
	{
		bool find = true;
		int l = 0, c;
		while (find && l < m.size())
		{
			c = 0;
			find = false;
			while (!find && c < m.size())
			{
				if (m[l][c].second == Surrounded)
					find = true;
				c++;
			}
			l++;
		}
	
		return find;
	}

	// --------------------------------------------------------------------

	void Kuhn::markLinesInit(typeMat & m, std::vector<bool> & mdL)
	{
		for (int i=0; i<m.size(); i++)
		{
			int j = 0;
			bool containt = false;
			while (containt == false && j<m.size())
			{
				if (m[i][j].second == Surrounded)
					containt = true;
				j++;
			}
			if (containt == false)
			{
				mdL[i] = true;
			}
		}
		/*-
		std::string msg = "mk l init ";
		for (int i=0; i<m.size(); i++)
		{
			msg += std::to_string(mdL[i]) + " ";
		}
		logger(Logger::INFO) << msg;//-*/
	}

	// --------------------------------------------------------------------

	bool Kuhn::markRows(typeMat & m, std::vector<bool> & mdL, std::vector<bool> & mdR)
	{
		bool bool_mR = false;
		for (int i=0; i<m.size(); i++)
		{
			if (mdL[i] == true)
			{
				int j = 0;
				for (int j=0; j<m.size(); j++)
				{
					if (m[i][j].second == Crossed)
					{
						if (mdR[j] == false)
							bool_mR = true;
						mdR[j] = true;
					}
				}
			}
		}
		/*-
		std::string msg = "mk r ";
		for (int i=0; i<m.size(); i++)
		{
			msg += std::to_string(mdR[i]) + " ";
		}
		logger(Logger::INFO) << msg;//-*/
	
		return bool_mR;
	}

	// --------------------------------------------------------------------

	bool Kuhn::markLines(typeMat & m, std::vector<bool> & mdL, std::vector<bool> & mdR)
	{
		bool bool_mL = false;
		for (int j=0; j<m.size(); j++)
		{
			if (mdR[j] == true)
			{
				int i = 0;
				for (int i=0; i<m.size(); i++)
				{
					if (m[i][j].second == Surrounded)
					{
						if (mdL[i] == false)
							bool_mL = true;
						mdL[i] = true;
					}
				}
			}
		}
		/*-
		std::string msg = "mk l" ;
		for (int i=0; i<m.size(); i++)
		{
			msg += std::to_string(mdL[i]) + " ";
		}
		logger(Logger::INFO) << msg;//-*/
	
		return bool_mL;
	}

	// --------------------------------------------------------------------

	void Kuhn::subtractionPartTable(typeMat & m, std::vector<bool> & mdL, std::vector<bool> & mdR)
	{
		int min = INT_MAX;
		for (int i=0; i<m.size(); i++)
		{
			if(mdL[i] == true)
			{
				/*-
				std::string msg = "test ligne : " + std::to_string(i+1);
				logger(Logger::INFO) << msg;//-*/
				for (int j=0; j<m.size(); j++)
				{
					if(mdR[j] == false && min > m[i][j].first)
					{
						min = m[i][j].first;
						/*-
						std::string msg = "col : " + std::to_string(j+1);
						logger(Logger::INFO) << msg;//-*/
					}
				}
			
			}
		}
		/*-
		std::string msg = "min : " + std::to_string(min);
		logger(Logger::INFO) << msg;//-*/
		for (int i=0; i<m.size(); i++)
		{
			for (int j=0; j<m.size(); j++)
			{
				if(mdL[i] == true && mdR[j] == false)
					m[i][j].first -= min;
				if(mdL[i] == false && mdR[j] == true)
					m[i][j].first += min;
			}
		}
	}
}

