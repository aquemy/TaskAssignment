//////////////////////////////////////////////////////////////////////////////
//
// <ut-environment.cpp>
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

#include <sif.hpp>

using namespace std;
using namespace sif;

int main(void)
{
    /**
     * Unit tests for environment
     */
    try
    {
      	SimpleSP spa;
        Coordonate<2,int> coord;
        
      	// Test for addObject()
      	
        // Add some resources
      	Environment<2, int, int> env;

        std::vector<AResource*> res;
        for(unsigned i = 0; i < 5; i++)
        {
            coord[0] = i;
            coord[1] = 1;
            res.push_back(new Resource<2,int,int>(coord, 100, false, spa));
        }
        
        env.addObject(res);
        
        if(env.getResources() != res)
			throw std::runtime_error("Error in expectations for first test");

        // Add some taskSpots
        Task t;
        StepConstraint sc(0, t, ConstraintComp::GREATER, 500);
        ConstraintSystem constraintSystem;
        constraintSystem.push(&sc);
        
        std::vector<ATaskSpot*> ts;
        for(unsigned i = 0; i < 5; i++)
        {
            coord[0] = i;
            coord[1] = 4;
            ts.push_back(new TaskSpot<2,int>(coord, std::ref(t), [](int& i, double _time){ return i+0.001*_time; }));
        }
        
        env.addObject(ts);
        
        if(env.getTaskSpots() != ts)
			throw std::runtime_error("Error in expectations for second test");

		// Test for update()
		env.update(0);
		env.update(-10);
		env.update(10);
			
      	// Test for _dump()
      	env.dump();
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}
