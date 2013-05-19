//////////////////////////////////////////////////////////////////////////////
//
// <aEnvironment.hpp>
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

#ifndef _SIF_AENVIRONMENT_
#define _SIF_AENVIRONMENT_

#include <vector>

#include <SIF/environment/spatialData.hpp>
#include <SIF/environment/aResource.hpp>

namespace sif
{

class AResource;
class SpatialData;

/** AEnvironment : Abstract class for environment.

@see sif::Environment
*/

class AEnvironment
{
public :

    /**
     * Update environment by updating all its components
     * @param _time Ellapsed time since the last update
     */
    void update(double _time);
    
    /**
     * Add resource to the environment
     * @param _resource New resource
     */
    void addObject(AResource& _resource);
    
    /**
     * Add resources to the environment
     * @param _resources Vector of resources
     */
    void addObject(std::vector<AResource*>& _resources);

    /**
     * setSpatialData
     * @param _spatialData New spatialData
     */
    void setSpatialData(SpatialData& _spatialData);
    
    /**
     * Add taskSpot to the environment
     * @param _taskSpot New taskSpot
     */
    void addObject(ATaskSpot& _taskSpot);
    
    /**
     * Add taskSpots to the environment
     * @param _taskSpots Vector of taskSpots
     */
    void addObject(std::vector<ATaskSpot*>& _taskSpots);
    
    /**
     * Get TaskSpots
     * @return Vector of TaskSpots
     */
    std::vector<ATaskSpot*>& getTaskSpots();
    
    /**
     * Get Resources
     * @return Vector of Resources
     */
    std::vector<AResource*>& getResources();
    
    /**
     * Debug function to show all informations about the class
     */
    void dump();

protected :

    /**
     * Implementation for dump function
     */
    virtual void _dump() = 0;

    std::vector<ATaskSpot*> taskSpots;
    std::vector<AResource*> resources;
    SpatialData* spatialData;
    
};


}

#endif // _SIF_AENVIRONMENT_

