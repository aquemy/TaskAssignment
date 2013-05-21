//////////////////////////////////////////////////////////////////////////////
//
// <l1-basicSimulation.cpp>
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

#include <exception>
#include <cassert>
#include <functional>
#include <random>

#include <sif.hpp>

using namespace std;
using namespace sif;

int main(void)
{
    
    try
    {
        // Random engine
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 10);
    
        // Create simple 2D environment
        Environment<2, int, int> env;
        
        // Add some resources randomly
        SimpleSP spa;
        Coordonate<2,int> coord;

        std::vector<AResource*> res;
        for(unsigned i = 0; i < 5; i++)
        {
            coord[0] = dis(gen);
            coord[1] = dis(gen);
            res.push_back(new Resource<2,int,int>(coord, 100, false, spa));
        }
        
        env.addObject(res);
        
        // Create some tasks and the constraintSystem
        Task t;
        StepConstraint sc(0, t, ConstraintComp::GREATER, 500);
        ConstraintSystem constraintSystem;
        constraintSystem.push(&sc);
        
        // Add some taskSpots
        std::vector<ATaskSpot*> taskSpots;
        for(unsigned i = 0; i < 5; i++)
        {
            coord[0] = dis(gen);
            coord[1] = dis(gen);
            taskSpots.push_back(new TaskSpot<2,int>(coord, std::ref(t), [](int& i, double _time){ return i+0.001*_time; }));
        }
        
        env.addObject(taskSpots);
        
        // Assignment
        Kuhn assignment;
        
        // Strategies creation
        SimpleStrategy<2,int> s1(assignment);
        
        // Model creation
        ManualModel<2,int> model(s1);
        
        // IA Creation
        IA<2,int> ia(model, constraintSystem);
        
        // Stop criterion
        TimeContinue cont(5);
        Controller::addContinue(cont);
        
        // Step Environment
        unsigned envDelay = 500; // ms
        auto envController = bind(&Environment<2,int,int>::update, std::ref(env), placeholders::_1);
        Step envStep(envController, envDelay);
        Controller::addStep(envStep);
        
        // Step DUMP
        unsigned dumpDelay = 500; // ms
        auto dump = bind(&Environment<2,int,int>::dump, std::ref(env));
        Step dumpStep(dump, dumpDelay);
        Controller::addStep(dumpStep);
        
        // Step IA
        unsigned iaDelay = 1000; // ms
        auto iaController = bind(&IA<2,int>::update, std::ref(ia), placeholders::_1);
        Step iaStep(iaController, iaDelay);
        Controller::addStep(iaStep);
        
        // Init and launch the simulation
        Controller::init(ia, env);
        Controller::run();
        
        // Free Memory
        for(auto e : taskSpots)
            delete e;
        for(auto e : res)
            delete e;
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}


