//////////////////////////////////////////////////////////////////////////////
//
// <resource.cpp>
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

#include <string>

namespace sif
{
    template <int Dim, class Type, class Data>
    Resource<Dim, Type, Data>::Resource(Coordonate<Dim, Type> _coord, double _velocity, bool _busy, ShortestPath& _spa) :
        AResource(_velocity, _busy, _spa),
        DynamicObject<Dim, Type>(_coord)
    { }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::move(Direction<Dim> _dir, double _time)
    { 
        Coordonate<Dim, Type> tcoord = Object<Dim, Type>::coord;
        // New position on the direction specified
        tcoord[_dir.getValue().first] += _dir.getValue().second*(velocity*_time); 
        if(true) // TEST IN SPACE + NOT COLLIDING
            Object<Dim, Type>::coord = tcoord;
    }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::setAssignment(TaskSpot<Dim, Type>& _assignment)
    { 
        assignment = _assignment;
    }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::update(double _time)
    { 
        AResource::update(_time);
    }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::_dump()
    {
        std::string coordString;
        std::string status;
        for(auto e : DynamicObject<Dim, Type>::coord)
            coordString+= std::to_string(e) + " ";

        if(busy)
            status = "Busy";
        else
            status = "Free";

        std::string message = std::to_string((long int)this)+" ( "+coordString+") | Status : "+status;
        logger(Logger::INFO) << message;
    }
}


