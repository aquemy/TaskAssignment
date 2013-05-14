//////////////////////////////////////////////////////////////////////////////
//
// <ut-constraint.cpp>
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
#include <functional>

#include <sif.hpp>

using namespace std;
using namespace sif;

int i = 0;

void foo()
{ i++ ;}

void bar()
{ i-- ;}

int main(void)
{
    /**
     * Unit tests for constraint classes
     */
    try
    {
        // Creation of a Task
        Task t;
        
        // Creation of a StepConstraint
        StepConstraint sc(0, t, ConstraintComp::GREATER, 500, foo, bar, 0, 10);
        
        // Should be false and i = 0
        if(sc() || i != 0)
            throw runtime_error("Error in expectations for first test");
        
        // Change to 501
        t.update(0, [](int& i) -> int { return i+501;});
        
        // Should be true and i = 1
        if(!sc() || i != 1)
            throw runtime_error("Error in expectations for second test");
        
        // Change to 498
        t.update(0, [](int& i) -> int { return i-3;});
        
        // Should be true and i = 1
        if(!sc()  || i != 1)
            throw runtime_error("Error in expectations for third test");
        
        // Change to 489
        t.update(0, [](int& i) -> int { return i-9;});
        
        // Should be false and i = 0
        if(sc() || i != 0)
            throw runtime_error("Error in expectations for fourth test");

    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}


