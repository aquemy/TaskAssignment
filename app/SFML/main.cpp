//////////////////////////////////////////////////////////////////////////////
//
// <main.cpp>
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

#include <iostream>
#include <exception>
#include <cassert>
#include <functional>
#include <random>

#include <SFML/Graphics.hpp>
#include <sif.hpp>

#include "src/environment.cpp"
#include "src/drawcontroller.cpp"

using namespace std;
using namespace sif;

int main(int argc, char *argv[])
{
    (void) argc;
    
    const unsigned xsize = 590;
    const unsigned ysize = 590;
    
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text labelTask("Value : 0", font, 25);
    labelTask.setColor(sf::Color::Black);
    sf::Text constraintNotif("Contrainte atteinte !", font, 25);
    constraintNotif.setColor(sf::Color::Black);
    constraintNotif.setPosition(100, 100);
    
    bool constraintReached = false;

    try
    {
        // Create the Window and the View
        sf::RenderWindow window(sf::VideoMode(800,600), "SIF Example");
    
        // Create simple 2D environment
        Environment<2, int, int> env;
        DEnvironment envi(sf::Vector2f(xsize, ysize), env);
        
        // Add some resources randomly
        SimpleSP spa;
        
        // Create some tasks and the constraintSystem
        Task t;
        StepConstraint sc(0, t, ConstraintComp::GREATER, 5000, [&]() { constraintReached = true; } );
        ConstraintSystem constraintSystem;
        constraintSystem.push(&sc);
        
        // Assignment
        Kuhn assignment;
        
        // Strategies creation
        SimpleStrategy<2,int> s1(assignment);
        
        // Model creation
        ManualModel<2,int> model(s1);
        
        // IA Creation
        IA<2,int> ia(model, constraintSystem);
        
        // Stop criterion
        TimeContinue cont(25);
        Controller::addContinue(cont);
        
        // Step Environment
        unsigned envDelay = 100; // ms
        auto envController = bind(&Environment<2,int,int>::update, std::ref(env), placeholders::_1);
        Step envStep(envController, envDelay);
        Controller::addStep(envStep);
        
        // Step DUMP
        unsigned dumpDelay = 5000; // ms
        auto dump = bind(&Environment<2,int,int>::dump, std::ref(env));
        Step dumpStep(dump, dumpDelay);
        Controller::addStep(dumpStep);
        
        // Step IA
        unsigned iaDelay = 100; // ms
        auto iaController = bind(&IA<2,int>::update, std::ref(ia), placeholders::_1);
        Step iaStep(iaController, iaDelay);
        Controller::addStep(iaStep);
        
        // Step SFML Draw
        unsigned sfmlDelay = envDelay; // ms
        auto sfmlController = bind(&SFML_Draw, std::ref(window),  
                    std::ref(envi), 
                    std::ref(labelTask), 
                    std::ref(t), 
                    std::ref(spa),
                    std::ref(env),
                    std::ref(constraintReached),
                    std::ref(constraintNotif),
                    placeholders::_1);
        Step sfmlStep(sfmlController, sfmlDelay);
        Controller::addStep(sfmlStep);
        
        // Init and launch the simulation
        Controller::init(ia, env);
        Controller::run();
        
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }

    return 0;
}

