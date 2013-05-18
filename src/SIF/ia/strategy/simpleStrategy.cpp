//////////////////////////////////////////////////////////////////////////////
//
// <simpleStrategy.cpp>
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

#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

#include <SIF/environment/coordonate.hpp>
#include <SIF/constraint/constraint.hpp>
#include <SIF/utils/logger.hpp>

namespace sif
{
    template <int Dim, class Type>
    SimpleStrategy<Dim, Type>::SimpleStrategy(Assignment& _assignment) :
        Strategy<Dim, Type>(_assignment),
        firstNotSatisfied(nullptr)
    { 
        // Creation of evalFunctions
        taskSpotEval = [=](ATaskSpot& i) -> int {
            if(&(i.getTask()) == &(firstNotSatisfied->getTask()))
                return 1;
            else
                return 0; 
        };
    }

    template <int Dim, class Type>
    int SimpleStrategy<Dim, Type>::evalSituation(SpatialData& _spatialData, ConstraintSystem& _constraintSystem)
    { 
        ConstraintSystem cs = _constraintSystem;
        firstNotSatisfied = nullptr;
        
        for(unsigned i = 0; i < cs.size(); i++)
        {
            if(!cs.top()->operator()())
            {
                firstNotSatisfied = cs.top();
                break;
            }    
            cs.pop();
        }
        
        logger(Logger::PROGRESS) << "SimpleStrategy : Eval constraints";
        
        std::string message = "First not satisfied constraint : "+std::to_string((long int)firstNotSatisfied);
        logger(Logger::INFO) << message;
        
        
        logger(Logger::PROGRESS) << "SimpleStrategy : Eval taskSpot"; 
        std::vector<ATaskSpot*> taskSpots = _spatialData.getTaskSpots();
        taskSpotsTable = EvalLoop(taskSpotEval, taskSpots);
        
        for(auto e : taskSpotsTable)
        {
            std::string message = std::to_string((long int)e.first)+" ("+std::to_string(e.second)+")";
            logger(Logger::INFO) << message;
        }
        
        logger(Logger::PROGRESS) << "SimpleStrategy : Eval (resources / taskSpots)";
        std::vector<AResource*> resources = _spatialData.getResources();
        auto busy = [](AResource* i) { return i->isBusy(); };
        resources.erase(std::remove_if(std::begin(resources), std::end(resources), busy), std::end(resources));
        
        for(auto res : resources)
        {
            for(auto ts : taskSpotsTable)
            {
                if(ts.second == 1)
                {
                    // TODO : use functors to define distance between objects
                    int dist = 0; // Manhatan distance
                    Coordonate<Dim, Type> coordR = static_cast<Resource<Dim, Type, int>*>(res)->getCoordonates();
                    Coordonate<Dim, Type> coordTS = static_cast<TaskSpot<Dim, Type>*>(ts.first)->getCoordonates();
                    
                    for(unsigned i = 0; i < Dim; i++)
                        dist += abs(coordR[i] - coordTS[i]);
                        
                    Strategy<Dim, Type>::couples[std::pair<AResource*, ATaskSpot*>(res, ts.first)] = dist;
                }
            }
        }
        
        int situationEval = 0;
        for(auto e : Strategy<Dim, Type>::couples)
            situationEval += e.second;

        return situationEval;
    }
    
}


