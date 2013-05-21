//////////////////////////////////////////////////////////////////////////////
//
// <environment.cpp>
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

#ifndef SIFAPP_ENV
#define SIFAPP_ENV

#include <vector>
#include <SFML/Graphics.hpp>
#include <SIF/environment/aEnvironment.hpp>

#include "resource.cpp"
#include "taskspot.cpp"

class DEnvironment
{
public :

    DEnvironment(sf::Vector2f _vect, sif::AEnvironment& _env) : env(&_env)
    {
        rectangle = sf::RectangleShape(_vect);
        rectangle.setFillColor(sf::Color(100, 250, 50));
        rectangle.setOutlineThickness(5);
        rectangle.setOutlineColor(sf::Color(250, 150, 100));
        rectangle.setPosition(5,5);
    }
    
    void update()
    {
        res.clear();
        for(auto e : env->getResources())
        {
            res.push_back(DResource(e));
        }
        ts.clear();
        for(auto e : env->getTaskSpots())
        {
            ts.push_back(DTaskSpot(e));
        }
    }
    
    void draw(sf::RenderWindow &rw) const
    {
        rw.draw(rectangle);
        for(auto e : ts)
            e.draw(rw);
        for(auto e : res)
            e.draw(rw);
        
    }   
    
protected :

    sf::RectangleShape rectangle;
    sif::AEnvironment* env;
    std::vector<DResource> res;
    std::vector<DTaskSpot> ts;
};

#endif
