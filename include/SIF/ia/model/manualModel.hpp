//////////////////////////////////////////////////////////////////////////////
//
// <manualModel.hpp>
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

#ifndef _SIF_MANUAL_MODEL_
#define _SIF_MANUAL_MODEL_

#include <SIF/ia/model.hpp>

namespace sif
{

/** ManualModel : Model without any decision or learning process

This model is the simpliest model that can be imagined. No relationship is defined between strategies and
the current strategy is defined by the user.

@see sif::IA, sif::Strategy, sif::Model
*/

template <class Coord, class Data>
class ManualModel : public Model<Coord, Data>
{

public : 
    
    /**
     * Update Model
     * @param _time Ellapsed time since the last update
     * @param _spatialData Data
     */
    virtual void update(double _time, SpatialData& _spatialData);
    
protected :
    
    /**
     * Evaluation of the situation : define how the situation has to be evaluated, according to the current strategy
     * @return Value of the evaluation
     */
    virtual int evalSituation();
    
    /**
     * Learning process
     */
    virtual void learn() ;
    
    /**
     * Decision process : mainly dedicated to change the strategy according to evaluation
     */
    virtual void decide();
    
    /**
     * Assignment process : mainly dedicated to assign through the assignment algorithm of the main strategy
     */
    virtual void assign();
    
    
    std::vector<Strategy<Coord, Data>*> strategies;  ///< Strategy used by the model
    Strategy<Coord, Data>& currentStrategy;                ///< Current strategy
    
};


}

#endif // _SIF_MANUAL_MODEL_

