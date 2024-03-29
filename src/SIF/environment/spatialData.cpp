//////////////////////////////////////////////////////////////////////////////
//
// <spatialData.cpp>
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

#include <SIF/environment/spatialData.hpp>
#include <SIF/utils/logger.hpp>

namespace sif
{
    SpatialData::SpatialData(AEnvironment* _env) :
        env(_env)
    { }

    void SpatialData::startPartitioning()
    {
        logger(Logger::PROGRESS) << "SpatialData : Start partitioning.";
        logger(Logger::PROGRESS) << "SpatialData : Finish partitioning.";
    }
    
    void SpatialData::startIndexing()
    {
        logger(Logger::PROGRESS) << "SpatialData : Start indexing.";
        
        if(resources == nullptr)
            delete resources;
        if(taskSpots == nullptr)
            delete taskSpots;
            
        resources = new SimpleIndex<AResource>(env->getResources());
        taskSpots = new SimpleIndex<ATaskSpot>(env->getTaskSpots());
        
        logger(Logger::PROGRESS) << "SpatialData : Finish indexing.";
    }
    
    Tree<ATaskSpot>& SpatialData::getTaskSpots() const
    {
        return *taskSpots;
    }
    
    Tree<AResource>& SpatialData::getResources() const
    {
        return *resources;
    }
    
    SpatialData::~SpatialData()
    {
        delete resources;
        delete taskSpots;
    }
    
}


