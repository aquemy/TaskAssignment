//////////////////////////////////////////////////////////////////////////////
//
// <space.cpp>
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

namespace sif
{
    
    template <int Dim, class Type>
    Space<Dim, Type>::Space()
    {
        boundaries.resize(Dim);
    }
    
    template <int Dim, class Type>
    void Space<Dim, Type>::setBoundaries(unsigned _pos, Type _left, Type _right)
    {
        if(_pos < Dim)
            boundaries[_pos] = std::pair<Type,Type>(_left, _right);
    }

    template <int Dim, class Type>    
    std::pair<Type,Type> Space<Dim, Type>::getBoundaries(unsigned _pos) const
    { 
        return boundaries[_pos];
    }
    
    template <int Dim, class Type>
    bool Space<Dim, Type>::inSpace(Coordonate<Dim,Type> _coord) const
    { 
        for(unsigned i = 0; i < Dim; i++)
        {
            if(_coord[i] < boundaries[i].first || _coord[i] > boundaries[i].second)
                return false;
        }
        
        return true;
    }
    
}


