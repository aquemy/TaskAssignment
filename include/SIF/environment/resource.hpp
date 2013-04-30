//////////////////////////////////////////////////////////////////////////////
//
// <resource.hpp>
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

#ifndef _SIF_RESOURCE_
#define _SIF_RESOURCE_

#include <SIF/environment/direction.hpp>
#include <SIF/environment/dynamicObject.hpp>
#include <SIF/environment/taskSpot.hpp>
#include <SIF/spa/shortestPath.hpp>
#include <SIF/graph/path.hpp>

namespace sif
{

/** Ressource : Ressource that can be affected to a task

A ressource is an object that can be affected to a task. It modelizes a point in space 
that can move. Thanks to a shortest path algorithm it is independant when it know
the Task Spot he has to join.

@see sif::Environment, sif::Object, sif::DynamicObject, sif::TaskSpot
*/

template <int Dim, class Type, class Data>
class Resource : public DynamicObject<Dim, Type>
{
public :
    
    /**
     * Constructor
     * @param _coord Initial coordonates
     * @param _velocity Velocity of the resource
     * @param _spa Shortest Path Algorithm
     */
    Resource(Coordonate<Dim, Type> _coord, double _velocity, ShortestPath& _spa);
    
    /**
     * Update Resource
     * @param _time Ellapsed time since the last update
     */
    virtual void update(double _time);
    
    /**
     * Move the resource in specified direction
     * @param _dir Direction
     * @param _time Ellapsed time since the last move
     */
    void move(Direction _dir, double _time);
        
    /**
     * Check if the resource is busy (it cannot be assigned)
     * @return boolean
     */
    bool isBusy();
    
    /**
     * Set a new assignement if it is possible
     * @param _assignment New assignment
     */
    void setAssignment(TaskSpot<Dim, Type>& _assignment);

protected : 
    
    /**
     * Check the collision according to the direction of the movement
     * @param _dir Direction
     * @return true is colliding, false otherwise
     */
    bool colliding(Direction _dir);
    
    double velocity;                                ///< Velocity of the ressource
    Path<Data> path;                                ///< Path to reach the assignment
    TaskSpot<Dim, Type>* assignment;                ///< Assignment
    ShortestPath& spa;                              ///< Shortest path algorithm
};


}

#endif // _SIF_RESOURCE_

