//////////////////////////////////////////////////////////////////////////////
//
// <kuhn.hpp>
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

#ifndef _SIF_KUHN_
#define _SIF_KUHN_

#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

#include <SIF/assignment/assignment.hpp>

namespace sif
{

/** Kuhn : Algorithm which solves the assignment problem

Kuhn is an algorithm wihch solves the asssignment problem. Kuhn is also named the Hungarian method.

@see sif::Assignment
*/

class Kuhn : public Assignment
{
public :
    
    /**
     * Start the Kuhn method
     * @param _mymap A map which associates a pair of resource / taskSpot with a cost
     * @return A map from resource to TaskSpot
     */
    std::map<AResource*,ATaskSpot*> operator()(std::map<std::pair<AResource*, ATaskSpot*>, int> _mymap);

    
protected :
    
    std::vector<std::vector<int>> cost;     ///< Cost matrix
    
    typedef enum
	{
		Normal,
		Surrounded,
		Crossed
	} state;							///< 

	typedef std::vector <std::vector<std::pair<int, state> > > typeMat;

    /**
     * Checks if the matrix is totally marked
     * @param mdL Vector of boolean which enable to know if a line is marked
     * @param mdR Vector of boolean which enable to know if a row is marked
     * @return true if the 2 vectors are completely true (ie  only filled with 1), false otherwise
     */
	bool isFullmarked(std::vector<bool> & mdL, std::vector<bool> & mdR);
	
    /**
     * Subtracts minimum on each row & column
     * @param mat Cost matrix
     */
	void subtractionMins(typeMat & mat);
	
    /**
     * Looks for the line with less zero with Normal state
     * @param mat Cost matrix
     * @return Index of the line with less zero
     */
	int lineWLessZUncrossed (typeMat & m);
	
    /**
     * Changes state of the zero on line l and row c to Crossed
     * @param mat Cost matrix
     * @param value of the line to consider
     * @param value of the row to consider
     */
	void strikeZLocatedSameArea(typeMat & m, int l, int c);
	
    /**
     * Checks if there is one zero surrounded on each line & column
     * @param mat Cost matrix
     * @return true if there is a zero on each line & column, false otherwise
     */
	bool zeroOnAllRC(typeMat & m);
	
    /**
     * Looks if there is already a zero on the row c
     * @param mat Cost matrix
     * @param c Index of the row to consider
     * @return true if there is already a zero, false otherwise
     */
	bool ZSurrondSameCol(typeMat & m, int c);
	
    /**
     * Marked all lines containing no zero surrounded
     * @param mat Cost matrix
     * @param mdL Vector marked lines
     */
	void markLinesInit(typeMat & m, std::vector<bool> & mdL);
	
    /**
     * Marks all rows containing a zero crossed on a marked line
     * @param mat Cost matrix
     * @param mdL Vector marked lines
     * @param mdR Vector marked rows
     * @return true if there have been changes, false otherwise 
     */
	bool markLines(typeMat & m, std::vector<bool> & mdL, std::vector<bool> & mdR);
	
    /**
     * Marks all lines containing a zero surrounded on a marked column
     * @param mat Cost matrix
     * @param mdL Vector marked lines
     * @param mdR Vector marked rows
     * @return true if there have been changes, false otherwise 
     */
	bool markRows(typeMat & m, std::vector<bool> & mdL, std::vector<bool> & mdR);
	
    /**
     * Subtracts the minimum in the partial table
     * @param mat Cost matrix
     * @param mdL Vector marked lines
     * @param mdR Vector marked rows
     */
	void subtractionPartTable(typeMat & m, std::vector<bool> & mdL, std::vector<bool> & mdR);

};

}

#endif // _SIF_KUHN_

