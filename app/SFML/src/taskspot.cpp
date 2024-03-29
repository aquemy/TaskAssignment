//////////////////////////////////////////////////////////////////////////////
//
// <taskspot.cpp>
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

#ifndef SIFAPP_TS
#define SIFAPP_TS

#include <vector>
#include <SFML/Graphics.hpp>
#include <SIF/environment/aTaskSpot.hpp>
#include <SIF/environment/taskSpot.hpp>
#include <SIF/environment/coordonate.hpp>


class DTaskSpot
{
public:
    DTaskSpot(sif::ATaskSpot* _r) : r(_r)
    {
        rectangle = sf::RectangleShape(sf::Vector2f(10,10));
        rectangle.setFillColor(sf::Color::Red);
        update();
    }
    
    void update()
    {
        sif::Coordonate<2, int> c = static_cast<sif::TaskSpot<2,int>*>(r)->getCoordonates();
        rectangle.setPosition(sf::Vector2f(c[0], c[1]));
    }
    
    void draw(sf::RenderWindow &rw) const
    {
        rw.draw(rectangle);
    }   
    
protected :

    sf::RectangleShape rectangle;
    sif::ATaskSpot* r;

};

#endif
