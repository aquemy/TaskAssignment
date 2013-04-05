//////////////////////////////////////////////////////////////////////////////
//
// <stepConstraint.hpp>
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

#ifndef _SIF_STEP_CONSTRAINT_
#define _SIF_STEP_CONSTRAINT_

namespace sif
{

enum ConstraintComp
{
    GREATER = 0,
    LESSER = 1
};

/** StepConstraint : Special constraint

StepConstraint is a special constraint related to the step.

@see sif::Constraint
*/

class StepConstraint : public Constraint
{
public :

    /**
     * Default constructor
     * @param _task Task concerned by the constraint
     * @param _comp Comparaison operator
     * @param _step Step value
     * @param _reachCondition Callback function called when the constraint is satisfied
     * @param _breakCondition Callback function called when the constraint is not satisfied
     * @param _rT Right value of the tolerance interval
     * @param _lT Left value of the tolerance interval
     */
    StepConstraint(Task& _task, 
        ConstraintComp _comp, 
        int _step,
        std::function<void()> _reachCondition = []{},
        std::function<void()> _breakCondition = []{},
        int _rT = 0, 
        int _lT = 0
   )
   
   /**
     * Check the constraint satisfaction and launch callback function if needed
     * @return boolean
     */ 
   virtual bool operator()();

protected :

    ConstraintComp op;                      ///< Comparaison operator
    int step;                               ///< Value of the step
    Task& task;                             ///< Reference on the task
    int lastValue;                          ///< Value at the last check
    int leftTolerance;                      ///< Value for the left tolerance
    int rightTolerance;                     ///< Value for the right tolerance
    
    std::function<void()> breakCondition;   ///< Called when the constraint is not satisfied
    std::function<void()> reachCondition;   ///< Called when the constraint is satisfied

};

}

#endif // _SIF_STEP_CONSTRAINT_

