//////////////////////////////////////////////////////////////////////////////
//
// <timeContinue.hpp>
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

#ifndef _SIF_TIME_CONTINUE_
#define _SIF_TIME_CONTINUE_

#include <chrono>

#include <SIF/core/continue/continue.hpp>

namespace sif
{

/** TimeContinue : Criterion for ending the calculation / simulation after a user-defined time

Criterion for ending the calculation / simulation after a user-defined time

@see sif::Continue, sif::StepsContinue, sif::Controller
*/

class TimeContinue : public Continue
{
public :
    
    /**
     * Constructor with time in seconds
     * @param _sec Time in seconds
     */
    TimeContinue(double _sec);
    
protected :
    
    /**
     * Implementation of the test
     * @return boolean
     */
    virtual bool _check();
    
    bool start;                                         ///< Boolean to know if the chrono is started
    double sec;                                         ///< Number of seconds to reach
    std::chrono::steady_clock::time_point startTime;    ///< Time when the chrono has been started
};

}

#endif // _SIF_TIME_CONTINUE_

