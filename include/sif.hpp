//////////////////////////////////////////////////////////////////////////////
//
// <SIF.hpp>
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

#ifndef _SIF_HEADER_
#define _SIF_HEADER_

// Config
#include <SIF/core/config.hpp>
#include <SIF/core/using.hpp>

// Utils
#include <SIF/utils/baseLogger.hpp>
#include <SIF/utils/logger.hpp>
#include <SIF/utils/timeManagement.hpp>

// Assignment
#include <SIF/assignment/assignment.hpp>
#include <SIF/assignment/assignmentFactory.hpp>
#include <SIF/assignment/kuhn.hpp>

// Constraint
#include <SIF/constraint/constraint.hpp>
#include <SIF/constraint/constraintSystem.hpp>
#include <SIF/constraint/customConstraint.hpp>
#include <SIF/constraint/stepConstraint.hpp>

// Core
#include <SIF/core/continue/continue.hpp>
#include <SIF/core/continue/stepsContinue.hpp>
#include <SIF/core/continue/timeContinue.hpp>
#include <SIF/core/activePolicy.hpp>
#include <SIF/core/controller.hpp>
#include <SIF/core/multiThread.hpp>
#include <SIF/core/observable.hpp>
#include <SIF/core/observablePolicy.hpp>
#include <SIF/core/observer.hpp>
#include <SIF/core/passivePolicy.hpp>
#include <SIF/core/singleThread.hpp>
#include <SIF/core/step.hpp>
#include <SIF/core/threadingModel.hpp>

// Environment
#include <SIF/environment/aCoordonate.hpp>
#include <SIF/environment/aEnvironment.hpp>
#include <SIF/environment/aResource.hpp>
#include <SIF/environment/aTaskSpot.hpp>
#include <SIF/environment/coordonate.hpp>
#include <SIF/environment/direction.hpp>
#include <SIF/environment/dynamicObject.hpp>
#include <SIF/environment/environment.hpp>
#include <SIF/environment/eval.hpp>
#include <SIF/environment/object.hpp>
#include <SIF/environment/obstacle.hpp>
#include <SIF/environment/resource.hpp>
#include <SIF/environment/space.hpp>
#include <SIF/environment/spatialData.hpp>
#include <SIF/environment/square.hpp>
#include <SIF/environment/staticObject.hpp>
#include <SIF/environment/task.hpp>
#include <SIF/environment/taskSpot.hpp>

// Graph
#include <SIF/graph/aPath.hpp>
#include <SIF/graph/atlasGrid.hpp>
#include <SIF/graph/movement.hpp>
#include <SIF/graph/path.hpp>
#include <SIF/graph/quadTree.hpp>
#include <SIF/graph/rTree.hpp>
#include <SIF/graph/simpleIndex.hpp>
#include <SIF/graph/tree.hpp>
#include <SIF/graph/treeFactory.hpp>

// IA
#include <SIF/ia/ia.hpp>
#include <SIF/ia/model.hpp>
#include <SIF/ia/strategy.hpp>
#include <SIF/ia/model/manualModel.hpp>
#include <SIF/ia/strategy/simpleStrategy.hpp>

// Shortest Path Algorithm
#include <SIF/spa/aStar.hpp>
#include <SIF/spa/simpleSP.hpp>
#include <SIF/spa/shortestPath.hpp>
#include <SIF/spa/shortestPathFactory.hpp>

#endif // _SIF_HEADER_
