//////////////////////////////////////////////////////////////////////////////
//
// <simpleStrategy.hpp>
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

#ifndef _SIF_SIMPLE_STRATEGY_
#define _SIF_SIMPLE_STRATEGY_

#include <SIF/ia/strategy.hpp>
#include <SIF/constraint/constraintSystem.hpp>

namespace sif
{

/** SimpleStrategy : Defines a simple strategy

@see sif::Model,
*/
    
template <int Dim, class Type, class Data>
class SimpleStrategy : public Strategy<Dim, Type, Data>
{
public :

    /**
     * Constructor
     * @param _assignment Assigment algorithm
     */
    SimpleStrategy(Assignment& _assignment);
    
    virtual int evalSituation(SpatialData& _spatialData, ConstraintSystem& _constraintSystem);

protected :

    Constraint* firstNotSatisfied;                      ///< First constraint not satisfied
    TaskSpotEval taskSpotEval;                          ///< Eval function for taskSpot
    EvalTable<ATaskSpot> taskSpotsTable;                ///< Evaluation of taskspots

};

}

#include <SIF/ia/strategy/simpleStrategy.cpp>

#endif // _SIF_SIMPLE_STRATEGY_

