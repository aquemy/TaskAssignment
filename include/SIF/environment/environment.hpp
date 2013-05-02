//////////////////////////////////////////////////////////////////////////////
//
// <environment.hpp>
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

#ifndef _SIF_ENVIRONMENT_
#define _SIF_ENVIRONMENT_

#include <vector>

#include <SIF/core/observer.hpp>
#include <SIF/environment/space.hpp>
#include <SIF/environment/object.hpp>
#include <SIF/environment/resource.hpp>
#include <SIF/environment/obstacle.hpp>
#include <SIF/environment/spatialData.hpp>

namespace sif
{

/** Environment : Modelize the environment of the problem

The environment is a description of the world used for the simulation or the calculation.
It contains the different objets that can evolve in a specific space.

@see sif::Space, sif::Object
*/

template <int Dim, class Type, class Data>
class Environment : public Observer
{
public :

        /**
     * Update environment by updating all its components
     * @param _time Ellapsed time since the last update
     */
    void update(double _time);

    /**
     * Add obstacle to the environment
     * @param _obstacle New obstacle
     */
    void addObject(Obstacle<Dim, Type>& _obstacle);

    /**
     * Add resource to the environment
     * @param _resource New resource
     */
    void addObject(Resource<Dim, Type, Data>& _resource);

    /**
     * Add taskSpot to the environment
     * @param _taskSpot New taskSpot
     */
    void addObject(TaskSpot<Dim, Type>& _taskSpot);

    /**
     * setSpatialData
     * @param _spatialData New spatialData
     */
    void setSpatialData(SpatialData& _spatialData);
    

protected :

    Space<Dim,Type> space;
    std::vector<Resource<Dim, Type, Data>> resources;
    std::vector<TaskSpot<Dim, Type>> taskSpots;
    std::vector<Obstacle<Dim, Type>> obstacles;
    SpatialData& spatialData;

};


}

#endif // _SIF_ENVIRONMENT_

