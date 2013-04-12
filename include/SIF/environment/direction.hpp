//////////////////////////////////////////////////////////////////////////////
//
// <direction.hpp>
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

#ifndef _SIF_DIRECTION_
#define _SIF_DIRECTION_

namespace sif
{

/**Direction : Define direction for dynamic objects

 At the moment the direction define constants for the 4 cardinal points : North, East, South, West.
In the future, they will depends on a general metric used in the environment. For instance, with a manhattan metric,
resources could only be moved in N,E,S,W directions but with an euclidian metric they could me mouved in 8 directions :
 N, E, S, W, NE, NW, SE, SW.

@see sif::Environment, sif::Object, sif::Ressource
*/

enum Direction
{
    NORTH,
    WEST,
    SOUTH,
    EAST
};

}

#endif // _SIF_DIRECTION_

