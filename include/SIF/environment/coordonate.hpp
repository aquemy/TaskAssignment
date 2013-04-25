//////////////////////////////////////////////////////////////////////////////
//
// <coordonate.hpp>
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

#ifndef _SIF_COORDONATE_
#define _SIF_COORDONATE_

#include <vector>

namespace sif
{

/** Coordonate : Cartesian coordonates for n-dimensional space

The coordonate object is designed to describe the space. First template represents
the number of dimensions and the second one represents the type of each coordonate.
This allows only cartesian system and uniform type representation at the moment.
Some inherited functions from std::vector have been deleted such as push_back and other size-related functions.

@see sif::Environment, sif::Space
*/

template <int Dim, class Type = int>
class Coordonate : public std::vector<Type>
{
    /**
     * Default constructor
     * Check the Type template is a numeric type with type_trait
     */
    Coordonate() ;
    
};


}

#endif // _SIF_COORDONATE_

