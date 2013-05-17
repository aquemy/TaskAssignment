//////////////////////////////////////////////////////////////////////////////
//
// <controller.hpp>
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

#ifndef _SIF_CONTROLLER_
#define _SIF_CONTROLLER_

#include <vector>
#include <list>

#include <SIF/core/step.hpp>
#include <SIF/core/continue/continue.hpp>
#include <SIF/environment/aEnvironment.hpp>
#include <SIF/environment/environment.hpp>
#include <SIF/environment/spatialData.hpp>
#include <SIF/ia/ia.hpp>

namespace sif
{

/** Controller : Main controller of the application

The controller is a static class that is the entry point of the execution flux.

*/

class Controller
{
public :
    
    /**
      * Default contructor
      */
     Controller();
    
     /**
      * Default destructor
      */
     ~Controller();
     
     /**
     * Set the environment
     * @param _env The environment of the simulation
     */
    static void setEnvironment(AEnvironment& _env);

    /**
     * Add a stop criterion
     * @param _cont Criterion
     */
    static void addContinue(Continue& _cont);
    
    /**
     * Add a step to the controller, at the end of the list
     * @param _step Step to add
     */
    static void addStep(Step _step);
    
    /**
     * Add a step to the controller
     * @param _step Step to add
     * @param _pos Position of the step in the list
     */
    static void addStep(Step _step, unsigned _pos);
    
    /**
     * Static initialization
     * @param _ia IA for the simulation
     */
    template <int Dim, class Type, class Data>
    static void init(IA<Dim, Type>& _ia, Environment<Dim, Type, Data>& _env);
    
    /**
     * Start the space partitioning
     */
    static void startPartitioning();
    
    /**
     * Start the space indexing
     */
    static void startIndexing();
    
    /**
     * Run the simulation / computation
     */
    static void run();
    
protected :
    
    /**
     * Check if a stop criterion is reached
     * @return boolean
     */
    static bool checkContinue();
    
    static std::vector<Continue*> cont;
    static std::list<std::pair<Step, unsigned>> steps;
    static SpatialData* spatialData;
    static bool initialized;
    static AEnvironment* env;
};

}

#include <SIF/core/controller.cpp>

#endif // _SIF_CONTROLLER_

