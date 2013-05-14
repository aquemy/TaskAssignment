//////////////////////////////////////////////////////////////////////////////
//
// <it-ia.cpp>
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

void f()
{
    i++;
}

int main(void)
{
    /**
     * Integration tests for IA
     */
    try
    {
        // Eval Functions creation
        ConstraintEval ce = [](Constraint& i) -> int { return 0; };
        TaskSpotEval<2,int> tsp = [](TaskSpot<2, int>& i) -> int { return 0; };
        ResourceEval<2,int, int> re = [](Resource<2, int, int>& i) -> int { return 0; };
        Eval<int> e = [](int& i) -> int { return 0; };
        
        // Assignment
        Kuhn<2, int, int> assignment;
        
        // Strategies creation
        SimpleStrategy<2,int,int> s1(ce, tsp, re, re, e, assignment);
        
        // Model creation
        ManualModel<2,int,int> model(s1);
        
        // IA Creation
        IA<2,int,int> ia(model);
        
        // Create and set Spatial Data (normally done by the controller)
        SpatialData sd;
        ia.setSpatialData(sd);
        
        // Update process
        ia.update(0);
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}


