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
    Resource<Dim, Type, Data>::Resource(Coordonate<Dim, Type> _coord, double _velocity, bool _busy, ShortestPath<Dim, Type> _spa) :
        AResource(_velocity, _busy),
        DynamicObject<Dim, Type>(_coord),
        spa(_spa),
        path(nullptr)
    { }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::move(Direction<Dim> _dir, double _time)
    { 
    	if(_time < 0.)
    	{
			logger(Logger::WARNING) << "Negative time, fix to 0";
			_time = 0.;
    	}
	    Coordonate<Dim, Type> tcoord = Object<Dim, Type>::coord;
	    // New position on the specified direction 
	    tcoord[_dir.getValue().first] += _dir.getValue().second*(velocity*_time); 
	    if(true) // TEST IN SPACE + NOT COLLIDING
	        Object<Dim, Type>::coord = tcoord;
    }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::update(double _time)
    {
        logger(Logger::PROGRESS) << "Resource : update";
        if(assignment != nullptr)
        {
            logger(Logger::INFO) << "Resource : assignment found.";
            if(Resource<Dim, Type, Data>::getCoordonates() == static_cast<TaskSpot<Dim, Type>*>(assignment)->getCoordonates())
            {
                logger(Logger::INFO) << "Resource : Update taskSpot.";
                assignment->update(_time);
            }
            else if(path != nullptr)
            {
                logger(Logger::INFO) << "Resource : moving.";
                move(_time);
            }
            else
            {
                logger(Logger::INFO) << "Resource : path calculation.";

                path = spa(Resource<Dim, Type, Data>::getCoordonates(), 
                        static_cast<TaskSpot<Dim, Type>*>(assignment)->getCoordonates());
            }
        }
        else
        {
            logger(Logger::INFO) << "Resource : no assigment / wait.";
        }
    }
    
    template <int Dim, class Type, class Data>
    void Resource<Dim, Type, Data>::move(double _time)
    {
        unsigned remaining = _time*velocity;

        Movement<Dim> move = path->back();
        Coordonate<Dim, Type> resCoord = Object<Dim, Type>::getCoordonates();
        Coordonate<Dim, Type> resCoord2 = resCoord;
        if(move.first.getValue().second)
            if(remaining < move.second)
            {
                resCoord[move.first.getValue().first] += remaining;
                path->back().second -= remaining;
            }
            else
            {
                resCoord[move.first.getValue().first] += move.second;
                path->pop_back();
            }
        else
            if(remaining < move.second)
            {
                resCoord[move.first.getValue().first] -= remaining;
                path->back().second -= remaining;
            }
            else
            {
                resCoord[move.first.getValue().first] -= move.second;
                path->pop_back();
            }
        Object<Dim, Type>::coord = resCoord;
        
        std::string coordString1;
        std::string coordString2;
        for(auto e : resCoord2)
            coordString1+= std::to_string(e) + " ";
        for(auto e : Object<Dim, Type>::coord)
            coordString2+= std::to_string(e) + " ";
            
        std::string message = "Moving from : ("+coordString1+") to: ("+coordString2+") - offset : "+std::to_string(move.second); 
           
        logger(Logger::INFO) << message;
        
        if(path->empty())
        {
            delete path;
        }
        
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
    
    template <int Dim, class Type, class Data>
    Resource<Dim, Type, Data>::~Resource()
    {
        if(path != nullptr)
            delete path;
    }
}


