//////////////////////////////////////////////////////////////////////////////
//
// <spatialData.hpp>
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

#ifndef _SIF_SPATIAL_DATA_
#define _SIF_SPATIAL_DATA_


#include <SIF/environment/aEnvironment.hpp>
#include <SIF/environment/aResource.hpp>
#include <SIF/environment/aTaskSpot.hpp>
#include <SIF/graph/simpleIndex.hpp>

namespace sif
{

class AResource;
class AEnvironment;

/** SpatialData : Contains the index of the objets and the partition of the space.

This is the object that partition and index the environment. All objects that need this information need to use its interface.
Final user should not see this class.

*/

class SpatialData 
{

public : 
    
    /**
     * Constructor
     * @param _env Environment to work on
     */
    SpatialData(AEnvironment* _env);
    
    /**
     * Start the partition of the environment
     */
    void startPartitioning();
    
    /**
     * Start the indexation of the environment
     */
    void startIndexing();
    
    /**
     * Get TaskSpots
     * @return Tree that contains taskspots
     */
    Tree<ATaskSpot>& getTaskSpots() const;
    
    /**
     * Get Resources
     * @return Tree that contains Resources
     */
    Tree<AResource>& getResources() const;
    
    /**
     * Destructor
     */
    ~SpatialData();

protected : 

    // TODO : Generic tree for indexes
    SimpleIndex<ATaskSpot>* taskSpots;  ///< Indexed TaskSpots
    SimpleIndex<AResource>* resources;  ///< Indexed Resource
    AEnvironment* env;                  ///< Environment pointer in the case we would like to launch an algorithm once again
    
};


}

#endif // _SIF_SPATIAL_DATA_

