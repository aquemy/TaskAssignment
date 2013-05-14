//////////////////////////////////////////////////////////////////////////////
//
// <eval.hpp>
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

#ifndef _SIF_EVAL_
#define _SIF_EVAL_

#include <functional>
#include <map>
#include <vector>

#include <SIF/constraint/constraint.hpp>
#include <SIF/environment/taskSpot.hpp>
#include <SIF/environment/resource.hpp>

namespace sif
{

/** 
 *  Eval : Different types of eval function
*/

/** 
 *  EvalTable : A map of cost indexed by Data pointers
*/
template <class Data>    
using EvalTable = std::map<Data*,int>;

/** 
 *  Eval : Base for eval function
*/
template <class Data>
using Eval = std::function<int(Data&)>;

/** 
 *  EvalLoop : Evaluate a vector of Data
 * @param _eval Evaluation function
 * @param _data Vector of data to evaluate
 * @return EvalTable
*/
template <class Data>
EvalTable<Data> EvalLoop(Eval<Data> _eval, std::vector<Data*>& _data);

/** 
 * ConstraintEval : Typedef for the constraint evaluation
*/
using ConstraintEval = Eval<Constraint>;

/** 
 * TaskSpotEval : Typedef for the TaskSpot evaluation
*/
template <int Dim, class Type>
using TaskSpotEval = Eval<TaskSpot<Dim, Type>>;

/** 
 * ResourceEval : Typedef for the Resource evaluation
*/
template <int Dim, class Type, class Data>
using ResourceEval = Eval<Resource<Dim, Type, Data>>;

}

#include <SIF/environment/eval.cpp>

#endif // _SIF_EVAL_

