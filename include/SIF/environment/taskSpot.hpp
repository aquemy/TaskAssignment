//////////////////////////////////////////////////////////////////////////////
//
// <taskSpot.hpp>
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

#ifndef _SIF_TASK_SPOT_
#define _SIF_TASK_SPOT_

#include <functional>

#include <SIF/environment/aTaskSpot.hpp>
#include <SIF/environment/dynamicObject.hpp>
#include <SIF/environment/task.hpp>
#include <SIF/core/activePolicy.hpp>
#include <SIF/core/observable.hpp>

namespace sif
{

/** TaskSpot : Physical object that can modify a task

The TaskSpot is an object that can modify a task when a specific action occured.
Different types of TaskSpot are provided such as periodic ones.

@see sif::Task, sif::PeriodicTaskSpot, sif::Observable
*/

template <int Dim, class Type>
class TaskSpot : public ATaskSpot, public DynamicObject<Dim, Type>//, public Observable<ActivePolicy>
{
public :

    /**
     * Constructor
     * @param _coord Coordonates of the taskSpot
     * @param _t The associated task
     * @param _f Function which serves to update the task
     */
    TaskSpot(Coordonate<Dim, Type> _coord, Task& _t, std::function<int(int&)> _f);
    
    /**
     * Update Ressource
     */
    virtual void update(double _time);
    
protected :

    /**
     * Implementation of dump function
     */
    void _dump();
    
};

}

#include <SIF/environment/taskSpot.cpp>

#endif // _SIF_TASK_SPOT_

