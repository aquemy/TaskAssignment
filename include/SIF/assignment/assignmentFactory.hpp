//////////////////////////////////////////////////////////////////////////////
//
// <assignmentFactory.hpp>
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

#ifndef _SIF_ASSIGNMENT_FACTORY_
#define _SIF_ASSIGNMENT_FACTORY_

#include <SIF/assignment/kuhn.hpp>

namespace sif
{

/** AssignmentFactory : Instanciate assignment algorithm

This factory converts general data to specific data used for a specific assignment algorithm.

@see sif::Assignment
*/

class AssignmentFactory
{
public :

    /**
     * Kuhn instanciation : tranform data into a cost matrix
     * @param _resource Resources to assign
     * @param _taskSpot taskSpot to be affected
     * @return Kuhn instance (right-value)
     */   
    template <int Dim, class Type, class Data>
    static Kuhn<Dim, Type, Data>&& KuhnInstance(std::map<Resource<Dim, Type, Data>*, int> _resource, std::vector<TaskSpot<Dim, Type>*> _taskSpot);
    
};

}

#endif // _SIF_ASSIGNMENT_FACTORY_

