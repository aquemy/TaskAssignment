//////////////////////////////////////////////////////////////////////////////
//
// <aResource.hpp>
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

#ifndef _SIF_ARESOURCE_
#define _SIF_ARESOURCE_

#include <SIF/environment/direction.hpp>
#include <SIF/environment/dynamicObject.hpp>
#include <SIF/environment/taskSpot.hpp>
#include <SIF/environment/direction.hpp>
#include <SIF/environment/spatialData.hpp>
#include <SIF/spa/shortestPath.hpp>
#include <SIF/graph/aPath.hpp>

namespace sif
{

class SpatialData;

/** ARessource : Abstract resource

@see sif::Resource
*/

class AResource
{
public :

    /**
     * Constructor
     * @param _velocity Velocity of the resource
     * @param _busy Status of the resource
     * @param _spa Shortest Path Algorithm
     */
    AResource(double _velocity, bool _busy, ShortestPath& _spa);
    
    /**
     * Update Resource
     * @param _time Ellapsed time since the last update
     */
    virtual void update(double _time);
      
    /**
     * Check if the resource is busy (it cannot be assigned)
     * @return boolean
     */
    bool isBusy() const;
    
    /**
     * Set the status of the resource
     * @param _status Bool
     */
    void setBusy(bool _status);
    
    /**
     * Set spatialData
     * @param _spatialData New SpatialData
     */
    void setSpatialData(SpatialData& _spatialData);
    
    /**
     * Debug function to show all informations about the class
     */
    void dump();

protected : 

    /**
     * Implementation for dump function
     */
    virtual void _dump() = 0;
    
    bool busy;									///< Status of the resource
    double velocity;                            ///< Velocity of the ressource
    APath* path;                                ///< Path to reach the assignment
    SpatialData* spatialData;
    ATaskSpot* assignment;                      ///< Assignment
    ShortestPath& spa;                          ///< Shortest path algorithm
};


}

#endif // _SIF_ARESOURCE_

