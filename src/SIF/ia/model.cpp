//////////////////////////////////////////////////////////////////////////////
//
// <model.cpp>
// Copyright (C), 2013
//
// Adeline Bailly, Alexandre Quemy
//
// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  ue,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRModel at the following URL
// "http://www.cecill.info".
//
// In this respect, the user's attention is drawn to the risks assocmodelted
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

#include <algorithm>

namespace sif
{
    
    template <int Dim, class Type, class Data>
    void Model<Dim, Type, Data>::Model(Strategy<Dim, Type, Data>& _currentStrategy) :
        currentStrategy(_currentStrategy)
    { 
        addStrategy(_currentStrategy);
    }

    template <int Dim, class Type, class Data>
    void Model<Dim, Type, Data>::addStrategy(Strategy<Dim, Type, Data>& _strategy)
    { 
        strategies.push_back(&_strategy);
    }
    
    template <int Dim, class Type, class Data>
    void Model<Dim, Type, Data>::setCurrentStrategy(unsigned _pos)
    { 
        if(_pos < strategies.size())
            currentStrategy = *strategies[_pos];
    }
    
    template <int Dim, class Type, class Data>
    void Model<Dim, Type, Data>::setCurrentStrategy(Strategy<Dim, Type, Data>& _strategy)
    { 
        if(std::find(std::begin(strategies), std::end(strategies), &_strategy) != std::end(strategies))
            currentStrategy = _strategy;
    }
    
}


