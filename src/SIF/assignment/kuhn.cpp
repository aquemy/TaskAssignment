//////////////////////////////////////////////////////////////////////////////
//
// <kuhn.cpp>
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

#include <SIF/assignment/kuhn.hpp>

namespace sif
{

	template <int Dim, class Type, class Data>
    std::map<Resource<Dim, Type, Data>*,TaskSpot<Dim, Type>*> Kuhn<Dim, Type, Data>::operator()()
    {
    
    // map < pair < resource, taskSpot >, int(cost) >
    // Mettre INF sur case à ajouter pour faire une matrice carrée !
    
    // Step 1 : Lister toutes les Ressources / TaskSpot
    // Step 2 : Si nb(R) > nb(TS) alors add(nb(R)-nb(TS)) à TS sinon add(nb(TS)-nb(R)) à R pour créer 1 matrice carrée
    // Remplir la matrice de MAX_INT (inclure limits.h)
    // Modifier la matrice de cout en fonction de la liste de cout passée en param
    // Appliquer l'algo de Kuhn
    
    }

}

