//////////////////////////////////////////////////////////////////////////////
//
// <ressourceObject.hpp>
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

#ifndef _SIF_RESSOURCE_
#define _SIF_RESSOURCE_

namespace sif
{

/** Ressource : Ressource that can be affected to a task

A ressource is an object that can be affected to a task. It modelizes a point in space 
that can move. Thanks to a shortest path algorithm it is independant when it know
the Task Spot he has to join.

@see sif::Environment, sif::Object, sif::DynamicObject sif::TaskSpot
*/

template <class Coordonate>
class Ressource : public DynamicObject<Coordonate>
{

};


}

#endif // _SIF_RESSOURCE_
