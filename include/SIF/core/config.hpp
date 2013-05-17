//////////////////////////////////////////////////////////////////////////////
//
// <config.hpp>
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

#ifndef _SIF_CONFIG_
#define _SIF_CONFIG_

// Environment part
#ifdef SIF_DEFAULT_DIM
#define DEF_DIM SIF_DEFAULT_DIM
#endif

#ifdef SIF_DEFAULT_COORD_TYPE
#define DEF_COORD_TYPE SIF_DEFAULT_COORD_TYPE
#else
#define DEF_COORD_TYPE int
#endif

// Multi Threading
#ifdef SIF_MULTI_THREADING
#define SIF_THREADING_MODEL MultiThread
#else
#define SIF_THREADING_MODEL SingleThread
#endif

#endif // _SIF_CONFIG_

