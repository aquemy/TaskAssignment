//////////////////////////////////////////////////////////////////////////////
//
// <space.hpp>
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

#ifndef _SIF_SPACE_
#define _SIF_SPACE_

#include <vector>
#include <utility>

#include <SIF/environment/coordonate.hpp>

namespace sif
{

/** Space : Defines the space

It defines the space  by its coordonates system and its boundaries.

@see sif::Coordonate, sif::Environment
*/

template <int Dim, class Type>
class Space
{
public :
    
    /**
     * Constructor
     */
    Space();
    
    /**
     * Set boundaries for a specific dimension
     * @param _pos Dimension index
     * @param _left Left value
     * @param _right Right value
     */
    void setBoundaries(unsigned _pos, Type _left, Type _right);
    
    /**
     * Get boundaries for a specific dimension
     * @param _pos
     * @return left and right values in a std::pair
     */
    std::pair<Type,Type> getBoundaries(unsigned _pos) const;
    
    /**
     * Check if a point is in the space
     * @param _coord Coordonate of the point
     * @return boolean
     */
    bool inSpace(Coordonate<Dim,Type> _coord) const; 
    
    protected :
        std::vector<std::pair<Type,Type>> boundaries; /// Boundaries
};


}

#include <SIF/environment/space.cpp>

#endif // _SIF_SQUARE_

