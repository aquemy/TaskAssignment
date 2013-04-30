//////////////////////////////////////////////////////////////////////////////
//
// <resource.cpp>
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

#include <SIF/environment/resource.hpp>

namespace sif
{
    template <class Coord, class Data>
    Resource<Coord, Data>::Resource(Coord _coord, double _velocity, bool _busy, ShortestPath& _spa)
    { }
    
    template <class Coord, class Data>
    void Resource<Coord, Data>::update(double _time)
    { }
    
    template <class Coord, class Data>
    void Resource<Coord, Data>::move(Direction _dir, double _time)
    { }
    
    template <class Coord, class Data>    
    bool Resource<Coord, Data>::isBusy()
    { }
    
    template <class Coord, class Data>
    void Resource<Coord, Data>::setAssignment(TaskSpot<Coord>& _assignment)
    { }

    template <class Coord, class Data>
    bool Resource<Coord, Data>::colliding(Direction _dir)
    { }
    
}


