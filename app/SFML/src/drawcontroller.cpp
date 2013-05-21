//////////////////////////////////////////////////////////////////////////////
//
// <drawcontroller.cpp>
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

#ifndef SIFAPP_DRAW_CONTROLLER
#define SIFAPP_DRAW_CONTROLLER

#include <string>

#include <SIF/environment/aEnvironment.hpp>
#include <SIF/environment/task.hpp>
#include <SIF/spa/simpleSP.hpp>
#include <SFML/Graphics.hpp>

#include "environment.cpp"

void SFML_Draw(sf::RenderWindow& window, 
    DEnvironment& env, 
    sf::Text& labelTask, 
    sif::Task& t,
    sif::SimpleSP& spa,
    sif::AEnvironment& env2,
    bool& constraintReached,
    sf::Text& constraintNotif,
    double _time)
{
    if(window.isOpen())
    {
        // Add resources
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            sif::Coordonate<2, int> coord;
            coord[0] = pos.x;
            coord[1] = pos.y;
            sif::AResource* r = new sif::Resource<2,int,int>(coord, 5 / 1000., false, spa);
            env2.addObject(*r);
        }
        
        // Add TaskSpot
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            sif::Coordonate<2, int> coord;
            coord[0] = pos.x;
            coord[1] = pos.y;
            sif::ATaskSpot* r = new sif::TaskSpot<2,int>(coord, std::ref(t), [](int& i, double _time)
                { static double up = 0;
                    up += _time*0.0001;
                    if((int)up > 0)
                    {
                        up = 0;
                        return i + 1; 
                    }
                    else 
                        return i;
                }
            );
            env2.addObject(*r);
        }
        
        // To close the application
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
                
        //Update 
        labelTask.setString("Value : "+std::to_string(t.getValue()));
        env.update();
        
        // Drawing part
        window.clear();
        env.draw(window);
        window.draw(labelTask);
        if(constraintReached)
            window.draw(constraintNotif);
        window.display();
    }
    else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.create(sf::VideoMode(800,600), "SIF Example");
}

#endif
