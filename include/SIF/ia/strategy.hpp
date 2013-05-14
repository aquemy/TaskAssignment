//////////////////////////////////////////////////////////////////////////////
//
// <strategy.hpp>
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

#ifndef _SIF_STRATEGY_
#define _SIF_STRATEGY_

#include <SIF/environment/eval.hpp>
#include <SIF/assignment/assignment.hpp>
#include <SIF/environment/spatialData.hpp>
#include <SIF/constraint/constraintSystem.hpp>

namespace sif
{

/** Strategy : Defines the behavior of the IA at a precise moment

 * The strategy define the whole process of the evaluation and assignment

@see sif::Model,
*/

template <int Dim, class Type, class Data>
class Strategy
{
public :
    
    /**
     * Constructor
     * @param _constraintEval Eval function for constraints
     * @param _taskSpotEval Eval function for taskSpot
     * @param _resourceEval Eval function for resource
     * @param _globalResourceEval Global eval function for resource
     * @param _evalSituation Eval function for the situation
     * @param _assignment Assigment algorithm
     */
    Strategy(ConstraintEval& _constraintEval,
                    TaskSpotEval<Dim, Type>& _taskSpotEval,
                    ResourceEval<Dim,Type, Data>& _resourceEval, 
                    ResourceEval<Dim, Type, Data>& _globalResourceEval,
                    Eval<int> _evalSituation,
                    Assignment& _assigment
                    );
    
     /**
      * Perform the evaluation of the situation
      * @param _spatialData Data structures of the environments
      * @param _constraintSystem Constraints on tasks
      * @return Value of the evaluation
      */
    virtual int evalSituation(SpatialData& _spatialData, ConstraintSystem& _constraintSystem) = 0;
    
    /**
     * Perform the assignment of resources
     * @return assigment information
     */
    virtual std::map<Resource<Dim, Type, Data>*,TaskSpot<Dim, Type>*> assign();
    
protected :
    
    EvalTable<Constraint> constraintTable;              ///< Evaluation of constraints
    EvalTable<TaskSpot<Dim, Type>> taskSpotsTable;               ///< Evaluation of taskspots
    EvalTable<Resource<Dim, Type, Data>> resourceTable;                ///< Evaluation of resources
    EvalTable<Resource<Dim, Type, Data>> globalResourceTable;    ///< Global evaluation of resources

    ConstraintEval& constraintEval;                            ///< Eval function for constraints
    TaskSpotEval<Dim, Type>& taskSpotEval;                               ///< Eval function for taskSpot
    ResourceEval<Dim, Type, Data>& resourceEval;                              ///< Eval function for resource
    ResourceEval<Dim, Type, Data>& globalResourceEval;                  ///< Global eval function for resource
    Eval<int> evalSit;                                     ///< Eval function for the situation
   
    Assignment& assignment;                                     ///< Assignment algorithm
};

}

#include <SIF/ia/strategy.cpp>

#endif // _SIF_STRATEGY_

