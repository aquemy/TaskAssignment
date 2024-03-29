//////////////////////////////////////////////////////////////////////////////
//
// <dynamicObject.hpp>
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

#ifndef _SIF_DYNAMIC_OBJECT_
#define _SIF_DYNAMIC_OBJECT_

#include <SIF/core/activePolicy.hpp>
#include <SIF/environment/object.hpp>
#include <SIF/core/observable.hpp>

namespace sif
{

/** DynamicObject : Objects that can evolve in time

It defines an abstract API for object that can move during the simulation. 
By moving, we suggest physically or just changing its internal state.

@see sif::Environment, sif::Object, sif::StaticObject, sif::Ressource, sif::TaskSpot
*/

template <int Dim, class Type>
class DynamicObject : public Object<Dim, Type>//, public Observable<ActivePolicy>
{
public :
    
     /**
    * Constructor
    * @param _coord Coordonates of the resource
    */
    DynamicObject(Coordonate<Dim, Type> _coord);
    
    /**
     * Update dynamic object
     * @param _time Ellapsed time since the last update
     */
    virtual void update(double _time) = 0;
    
};

}

#include <SIF/environment/dynamicObject.cpp>

#endif // _SIF_DYNAMIC_OBJECT_

