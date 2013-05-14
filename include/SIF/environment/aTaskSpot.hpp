//////////////////////////////////////////////////////////////////////////////
//
// <aTaskSpot.hpp>
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

#ifndef _SIF_ATASK_SPOT_
#define _SIF_ATASK_SPOT_

#include <functional>

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

class ATaskSpot
{
public :

    /**
     * Constructor
     * @param _t The associated task
     * @param _f Function which serves to update the task
     */
    ATaskSpot(Task& _t, std::function<int(int&)> _f);

    /**
     * Update Ressource
     */
    virtual void update(double _time);
    
    /**
     * Debug function to show all informations about the class
     */
    void dump();
    
protected :
    
    /**
     * Implementation for dump function
     */
    virtual void _dump() = 0;
    
    std::function<int(int&)> f;
	Task& t;
    
};

}

#endif // _SIF_ATASK_SPOT_

