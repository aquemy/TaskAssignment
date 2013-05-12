//////////////////////////////////////////////////////////////////////////////
//
// <taskSpot.cpp>
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
    TaskSpot<Dim, Type>::TaskSpot(Coordonate<Dim, Type> _coord, Task& _t, std::function<int(int&)> _f) :
        DynamicObject<Dim, Type>(_coord),
    	t(_t), 
    	f(_f)
    { }
    
    template <int Dim, class Type>
    void  TaskSpot<Dim, Type>::update(double _time)
    {
    	t.update(f);
    }
    
}

