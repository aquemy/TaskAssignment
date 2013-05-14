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

#include <SIF/assignment/kuhn.hpp>

namespace sif
{

	template <int Dim, class Type, class Data>
    std::map<Resource<Dim, Type, Data>*,TaskSpot<Dim, Type>*> Kuhn<Dim, Type, Data>::operator()(std::map<std::pair<std::vector<Resource<Dim, Type, Data>>*, std::vector<TaskSpot<Dim, Type>>*>, int> _mymap)
    {
    
    std::vector<Resource<Dim, Type, Data>> _resource;
    std::vector<TaskSpot<Dim, Type>> _ taskSpot;
	
    // Step 1 : List of Resource & TaskSpot
    for (auto& eval : _mymap)
    {
    	if (std::find(_resource.begin(), _resource.end(), &*eval.first.first) == _resource.end())
		{  	// Recovery of resources
			_resource.push_back(eval.first.first);
		}
			
    	if (std::find(_taskSpot.begin(), _taskSpot.end(), &*eval.first.second) == _taskSpot.end())
		{	// Recovery of taskSpots
			_taskSpot.push_back(eval.first.second);
		}
		
    }
    
    // Step 2 : Creation of square matrix
    int sizeResource = _resource.size(), sizeTaskSpot = _taskSpot.size();
    if (sizeResource > sizeTaskSpot)
    {
    	for (int i=0; i<sizeResource - sizeTaskSpot; i++)
    	{
    		_taskSpot.push_back(new TaskSpot());
    	}
    }
    else if (sizeResource < sizeTaskSpot)
    {
    	for (int i=0; i<sizeTaskSpot - sizeResource; i++)
    	{
    		_resource.push_back(new Resource());
    	}
    }
	
    // Cost Matrix
	std::vector <std::vector<int> > cost(_resource.size());
	for (int i=0; i<_resource.size(); i++)
	{
		cost[i].resize(_taskSpot.size());
		for (int j=0; j<_taskSpot.size(); j++)
			cost[i][j] = -1;
	}
	
	for (auto& eval : _mymap)
	{
		cost[eval.first.first][eval.first.second] = eval.second;
	}
	for (int i=0; i<cost.size(); i++)
	{
		for (int j=0; j<cost.size(); j++)
			if (cost[i][j] == -1)
				cost[i][j] = INT_MAX;
	}
	
    // Mettre INF sur case à ajouter pour faire une matrice carrée !
    // Remplir la matrice de MAX_INT (inclure limits.h)
    
    // Modifier la matrice de cout en fonction de la liste de cout passée en param
    // Appliquer l'algo de Kuhn
    
    }

}

