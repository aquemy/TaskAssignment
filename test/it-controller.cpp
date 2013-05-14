//////////////////////////////////////////////////////////////////////////////
//
// <it-controller.cpp>
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

#include <sif.hpp>

using namespace std;
using namespace sif;

static int i = 0;

void f(unsigned ellapsedTime)
{
    cout << ellapsedTime << endl;
    i++;
}

int main(void)
{
    /**
     * Integration tests for controller
     */
    try
    {
        /*auto func = f;
        Step step(func, placeholder::_1);
        
        StepsContinue cont(5);
        TimeContinue cont_2(5);
        
        Controller::addContinue(cont);
        Controller::addContinue(cont_2);
        
        Controller::addStep(step);
        
        Controller::init();
        Controller::run();
        
        // Should return 5
        if(i != 5)
            throw runtime_error("Something is wrong with the controller");*/
        
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}

