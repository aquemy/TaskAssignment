//////////////////////////////////////////////////////////////////////////////
//
// <aResource.cpp>
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

#include <SIF/environment/aResource.hpp>
#include <SIF/utils/logger.hpp>

namespace sif
{

    AResource::AResource(double _velocity, bool _busy, ShortestPath& _spa) :
        velocity(_velocity),
        busy(_busy),
        spa(_spa)
    {}
    
    void AResource::update(double _time)
    { 
        logger(Logger::PROGRESS) << "Resource : update";
        if(assignment != nullptr)
        {
            logger(Logger::INFO) << "Resource : assignment found.";
            if(path != nullptr)
            {
                logger(Logger::INFO) << "Resource : moving.";
            }
            else
            {
                logger(Logger::INFO) << "Resource : path calculation.";
                /*template<class Data, int Dim, class Type>
    Path<Data>&& operator()(const Coordonate<Dim,Type>& _from,
                                                      const Coordonate<Dim, Type>& _to, 
                                                      const Tree<Data> _data);*/
                //path = spa();
            }
        }
        else
        {
            logger(Logger::INFO) << "Resource : no assigment / wait.";
        }
    }
    
    bool AResource::isBusy() const
    { 
        return busy;
    }
    
    void AResource::setBusy(bool _status)
    { 
        busy = _status;
    }
    
    void AResource::setSpatialData(SpatialData& _spatialData)
    { 
        spatialData = &_spatialData;
    }
    
    void AResource::dump()
    {
        _dump();
    }
    
}


