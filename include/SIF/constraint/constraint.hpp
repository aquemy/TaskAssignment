//////////////////////////////////////////////////////////////////////////////
//
// <constraint.hpp>
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

#ifndef _SIF_CONSTRAINT_
#define _SIF_CONSTRAINT_

#include <SIF/environment/task.hpp>

namespace sif
{

/** Constraint : General class for constraints

General class for constraints, has the level of the priority (int). Several types of constraints exist.

@see sif::ConstraintSystem, sif::StepConstraint, sif::PropConstraint, sif::CustomConstraint
*/

class Constraint
{
public :

    /**
     * Default constructor
     * @param _priority Constraint priority
     */ 
    Constraint(Task& _t, unsigned _priority);
    
    /**
     * Change the priority
     * @param _priority Constraint priority
     */ 
    void setPriority(unsigned _priority);
    
    /**
     * Get the priority
     * @return Constraint priority
     */ 
    unsigned getPriority() const;
    
    /**
     * Comparaison operator based on priority
     * @param _const Constraint to compare
     * @return boolean
     */
    bool operator<(Constraint& _const);
    
    /**
     * Check the constraint satisfaction and launch callback function if needed
     * @return boolean
     */ 
    virtual bool operator()() = 0;
    
    const Task& getTask() const;

protected :

    Task& t;
    unsigned priority;  ///< Priority of the constraint

};


/** ConstraintCompare : Functor to compare constraints on priority level

Functor to compare constraints on priority level

@see sif::ConstraintSystem, sif::StepConstraint, sif::PropConstraint, sif::CustomConstraint
*/
class ConstraintCompare
{
public :
    
    bool operator()(Constraint* _c1, Constraint* _c2);

};

}

#endif // _SIF_CONSTRAINT_

