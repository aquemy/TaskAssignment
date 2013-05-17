//////////////////////////////////////////////////////////////////////////////
//
// <model.hpp>
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

#ifndef _SIF_MODEL_
#define _SIF_MODEL_

#include <SIF/ia/strategy.hpp>

namespace sif
{

/** Model : Defines relationship between strategies and how the observation is done

Model defines the arrangement bewteen strategies and how the observation and all the IA process has to be carried out.

@see sif::IA, sif::Strategy
*/

template <int Dim, class Type>
class Model
{

public : 
    
    /**
     * Constructor
     * @param _currentStrategy Main strategy
     */
    Model(Strategy<Dim, Type>& _currentStrategy);
    
    /**
     * Update Model
     * @param _time Ellapsed time since the last update
     * @param _spatialData Data
     */
    virtual void update(double _time, SpatialData& _spatialData, ConstraintSystem& _constraintSystem)  = 0;
    
    /**
     * Add a strategy to the model
     * @param _strategy Strategy to add to the model 
     */
    void addStrategy(Strategy<Dim, Type>& _strategy);
    
    /**
     * Set current strategy
     * @param _pos Position of the strategy in the vector
     */
    void setCurrentStrategy(unsigned _pos);
    
    /**
     * Set current strategy, only if the strategy is in the model
     * @param _strategy Strategy to set as current strategy
     */
    void setCurrentStrategy(Strategy<Dim, Type>& _strategy);
    
protected :
    
    /**
     * Evaluation of the situation : define how the situation has to be evaluated, according to the current strategy
     * @return Value of the evaluation
     */
    virtual int evalSituation(SpatialData& _spatialData, ConstraintSystem& _constraintSystem) = 0;
    
    /**
     * Learning process
     */
    virtual void learn() = 0;
    
    /**
     * Decision process : mainly dedicated to change the strategy according to evaluation
     */
    virtual void decide() = 0;
    
    /**
     * Assignment process : mainly dedicated to assign through the assignment algorithm of the main strategy
     */
    virtual void assign() = 0;
   
    
    
    std::vector<Strategy<Dim, Type>*> strategies;        ///< Strategy used by the model
    Strategy<Dim, Type>& currentStrategy;                ///< Current strategy
    
};

}

#include <SIF/ia/model.cpp>

#endif // _SIF_MODEL_

