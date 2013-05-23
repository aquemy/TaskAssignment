//////////////////////////////////////////////////////////////////////////////
//
// <ut-resource.cpp>
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
     * Unit tests for resource
     */
    try
    {
    	Kuhn assignment;
        SimpleSP spa;
        Coordonate<2,int> coord, c;
        coord[0] = 1;
        coord[1] = 1;
        Resource<2,int,int>* res = new Resource<2,int,int>(coord, 100, false, spa);
		
		// Test for move()
		Direction<2> d(1,true);
		res->move(d, -1);

		if(res->getCoordonates() != coord)
			throw std::runtime_error("Error in expectations for test 1");
			
		res->move(d, 0);

		if(res->getCoordonates() != coord)
			throw std::runtime_error("Error in expectations for test 2");
			
		res->move(d, 1);

		if(res->getCoordonates() == coord)
			throw std::runtime_error("Error in expectations for test 3");

		// Test for update()
		res->update(-1.);
		logger(Logger::INFO) << "------";
		res->update(0.);
		logger(Logger::INFO) << "------";
		res->update(1.);
		
        // Add 1 taskSpot
		Task t;
        StepConstraint sc(0, t, ConstraintComp::GREATER, 500);
        ConstraintSystem constraintSystem;
        constraintSystem.push(&sc);
        
        coord[0] = 3;
        coord[1] = 3;
		TaskSpot<2,int>* ts = new TaskSpot<2,int>(coord, std::ref(t), [](int& i, double _time){ return i+0.001*_time; });
		
		res->setAssignment(*ts);
		
		c = res->getCoordonates();
		
		logger(Logger::INFO) << "-------------------------";
		res->update(-1.);
		
		if(res->getCoordonates() != c)
			throw std::runtime_error("Error in expectations for test 4");
			
		logger(Logger::INFO) << "------";
		res->update(0.);
		
		if(res->getCoordonates() != c)
			throw std::runtime_error("Error in expectations for test 5");
			
		logger(Logger::INFO) << "------";
		res->update(1.);
		
		if(res->getCoordonates() == c)
			throw std::runtime_error("Error in expectations for test 6");
		
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}

