//////////////////////////////////////////////////////////////////////////////
//
// <ia.hpp>
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

#ifndef _SIF_IA_
#define _SIF_IA_

#include <SIF/ia/model.hpp>

namespace sif
{

/** IA : 

IA

@see sif::Observer,
*/

template <class Coord, class Data>
class IA : public Observer
{
public :
    
    /**
     * Constructor
     * @param _model Model of IA
     * @param _assignement Assignment algorithm
     */
    IA(Model<Coord, Data>& _model, Assignment<Coord, Data>& _assignement);
    
    /**
     * Constructor
     * @param _model Model of IA
     * @param _assignement Assignment algorithm
     * @param _spatialData Spatial data used for strategies
     */
    IA(Model<Coord, Data>& _model, Assignment<Coord, Data>& _assignement, SpatialData& _spatialData);
    
    /**
     * Update IA
     * @param _time Ellapsed time since the last update
     */
    void update(double _time);
    
    /**
     * Set the model
     * @param _model New strategy model
     */
    void setModel(Model<Coord, Data>& _model);
    
    /**
     * Set the spatial data
     * @param _spatialData New spatialData
     */
    void setSpatialData(SpatialData& spatialData);

protected :

    SpatialData& spatialData;
    Model<Coord, Data>& model;
    
    
};


}

#endif // _SIF_IA_

