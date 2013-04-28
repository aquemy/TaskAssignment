//////////////////////////////////////////////////////////////////////////////
//
// <customConstraint.hpp>
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

#ifndef _SIF_CUSTOM_CONSTRAINT_
#define _SIF_CUSTOM_CONSTRAINT_

#include <functional>

#include <SIF/constraint/constraint.hpp>

namespace sif
{

/** CustomConstraint : Special constraint

CustomConstraint is a special constraint defined by the user.

@see sif::Constraint
*/

class CustomConstraint : public Constraint
{
public :

    /**
     * Default constructor
     * @param _cond Condition to satisfy the constraint
     * @param _reachCondition Callback function called when the constraint is satisfied
     * @param _breakCondition Callback function called when the constraint is not satisfied
     */
    CustomConstraint(unsigned _priority,
        std::function<bool()> _cond,
        std::function<void()> _reachCondition = []{},
        std::function<void()> _breakCondition = []{}
   );
   
   /**
     * Check the constraint satisfaction and launch callback function if needed
     * @return boolean
     */ 
   virtual bool operator()();

protected :

    std::function<bool()> cond;             ///< Constraint satisfaction
    bool lastValue;                                    ///< Value at the last check

    std::function<void()> breakCondition;   ///< Called when the constraint is not satisfied
    std::function<void()> reachCondition;   ///< Called when the constraint is satisfied

};

}

#endif // _SIF_CUSTOM_CONSTRAINT_

