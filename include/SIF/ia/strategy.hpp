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

namespace sif
{

/** Strategy : Defines the policy of the model

The Strategy is defined by the user, defines the policy of the model.

@see sif::Model,
*/

class Strategie
{
public : 
    
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
    virtual std::map<Resource*,TaskSpot*> assign() = 0;
    
protected :
    
    EvalTable<Constraint> constraintTable;              ///< Evaluation of constraints
    EvalTable<TaskSpot> taskSpotsTable;               ///< Evaluation of taskspots
    EvalTable<Resource> resourceTable;                ///< Evaluation of resources
    EvalTable<Resource> globalResourceTable;    ///< Global evaluation of resources

    ConstraintEval& constraintEval;                            ///< Eval function for constraints
    TaskSpotEval& taskSpotEval;                               ///< Eval function for taskSpot
    ResourceEval& resourceEval;                              ///< Eval function for resource
    ResourceEval& globalResourceEval;                  ///< Global eval function for resource
    Eval<void> evalSituation;                                     ///< Eval function for the situation
   
    Assignment& assigment;                                     ///< Assigment algorithm
};


}

#endif // _SIF_STRATEGY_

