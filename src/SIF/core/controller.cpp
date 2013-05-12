//////////////////////////////////////////////////////////////////////////////
//
// <controller.cpp>
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

#include <iterator>
#include <stdexcept> 

#include <SIF/core/controller.hpp>
#include <SIF/core/continue/continue.hpp>
#include <SIF/utils/logger.hpp>

namespace sif
{
    
std::vector<Continue*> Controller::cont;
std::list<std::pair<Step, unsigned>> Controller::steps;
SpatialData* Controller::spatialData;  
bool Controller::initialized = false;
AEnvironment* Controller::env;
    
Controller::Controller()
{
        
}
    
Controller::~Controller()
{
    logger(Logger::DEBUG) << "Delete Spatial Data.";
    delete Controller::spatialData;
}

void Controller::addEnvironment(AEnvironment& _env)
{
    Controller::env = &_env;
}

void Controller::addContinue(Continue& _cont)
{
    Controller::cont.push_back(&_cont);
}

void Controller::addStep(Step _step)
{
    Controller::steps.push_back(std::pair<Step, unsigned>(_step,0));
}

void Controller::addStep(Step _step, unsigned _pos)
{
    auto it = std::begin(steps);
    for(auto i = 0; i < _pos; i++,it++);
    steps.insert(it, std::pair<Step, unsigned>(_step,01));
}
    
void Controller::init()
{
    logger(Logger::PROGRESS) << "Init Controller.";
    
    // Check that there is a least one continue criterion
    if(Controller::cont.size() == 0)
        throw std::runtime_error("One criterion is requiered at least !");
        
    // If SpatialData is not specified, we created it
    if(spatialData == nullptr)
    {
        // If we have partition or indexing algorithm AND environment
        //if()
        std::cout << "A" << std::endl;
        spatialData = new SpatialData();
    }
    std::cout << "A" << std::endl;
    spatialData->startPartitioning();
    std::cout << "A" << std::endl;
    spatialData->startIndexing();
    std::cout << "A" << std::endl;
    //env->setSpatialData(*spatialData);
    std::cout << "A" << std::endl;
    Controller::initialized = true;
}

void Controller::startPartitioning()
{
    if(spatialData == nullptr)
        logger(Logger::DEBUG) << "Controller::startPartitioning : no SpatialData found !";
    else
        spatialData->startPartitioning();
}

void Controller::startIndexing()
{
    if(spatialData == nullptr)
        logger(Logger::DEBUG) << "Controller::startIndexing : no SpatialData found !";
    else
        spatialData->startIndexing();
}

void Controller::run()
{
    if(!Controller::initialized)
        throw std::runtime_error("Controller not initialized !");

    logger(Logger::PROGRESS) << "Run Controller.";
    
    auto startTime = std::chrono::steady_clock::now();
    
    while(Controller::checkContinue())
    {
        auto now = std::chrono::steady_clock::now();
        for(auto step : Controller::steps)
        {
            unsigned diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();
            if(step.second < diff / step.first.second)
            {
                step.second = diff / step.first.second;
                step.first.first(diff);
            }
    
        }
    }
}

bool Controller::checkContinue()
{
    bool res = true; 
    unsigned i = 0;
    
    while(res && i < cont.size())
    {
        res = cont[i]->operator()();
        i++;
    }
    
    return res;
}

}

