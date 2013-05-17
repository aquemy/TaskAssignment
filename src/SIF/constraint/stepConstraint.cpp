//////////////////////////////////////////////////////////////////////////////
//
// <stepConstraint.cpp>
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

#include <SIF/constraint/stepConstraint.hpp>

namespace sif
{
    StepConstraint::StepConstraint(unsigned _priority, Task& _task, 
        ConstraintComp _comp, 
        int _step,
        std::function<void()> _reachCondition,
        std::function<void()> _breakCondition,
        int _rT, 
        int _lT
   ) : 
   Constraint(_task, _priority),
            step(_step),
            op(_comp),
            reachCondition(_reachCondition),
            breakCondition(_breakCondition),
            rightTolerance(_rT),
            leftTolerance(_lT)
    {
        lastValue = false;
    }
    
    bool StepConstraint::operator()()
    {
        bool res;
        int x = Constraint::t.getValue();
        if(op == ConstraintComp::GREATER)
        {
            if(!lastValue)
            {
                 if(x > step)
                 {
                     res = true;
                     lastValue = true;
                     reachCondition();
                 }
                 else
                     res = false;
            }
            else
            {
                if(x > step - leftTolerance)
                     res = true;
                 else
                 {
                     res = false;
                     lastValue = false;
                     breakCondition();
                 }
            }
        }  
        else if (op == ConstraintComp::LESSER)
        {
            if(!lastValue)
            {
                 if(x <= step)
                 {
                     res = true;
                     lastValue = true;
                     reachCondition();
                 }
                 else
                     res = false;
            }
            else
            {
                if(x <= step - rightTolerance)
                     res = true;
                 else
                 {
                     res = false;
                     lastValue = false;
                     breakCondition();
                 }
            }
        }    
        
        return res;
            
    };

}

