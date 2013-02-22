//////////////////////////////////////////////////////////////////////////////
//
// <baseLogger.hpp>
// Copyright (C), 2013
//
// Adeline Bailly, Gabrielle Diaferia, Pauline Hubert, Alexandre Quemy
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

#ifndef _SIF_BASE_LOGGER_
#define _SIF_BASE_LOGGER_

#include <iostream>
#include <string>

namespace sif
{

class BaseLogger
{
public:
    BaseLogger(int _level, std::string _label, std::ostream& _os = std::clog, bool _quiet = false);
    
    BaseLogger(int _level, std::string _label,  std::string _logFile, std::ostream& _os = std::clog, bool _quiet = false);
    
    ~BaseLogger();
 
    BaseLogger* setNext(BaseLogger* _next);
        
    BaseLogger* getNext() const;
 
    void handle(const std::string msg, int priority);
    
    void startSerialize(int _level, std::string _logFile);
    
    void startSerialize(std::string _logFile);
    
    void stopSerialize(int _level);
    
    void stopSerialize();
        
    void setQuiet();
    
    void setQuiet(int _level);
        
    void setVerbose();
    
    void setVerbose(int _level);
        
    void setStatus(int _level, bool _status);
        
    void print(const std::string _msg, std::ostream* _stream);
    
    void log(std::string _msg);
 
    friend BaseLogger& operator<<(BaseLogger& _logger, const std::string _msg);
    
    BaseLogger(const BaseLogger&) = delete;
    BaseLogger& operator =(const BaseLogger&)  = delete;
        
protected:
    std::string label;
    int level;
    BaseLogger* next;
    bool quiet;
    std::ostream* os;
    std::string logFile;
    std::ostream* of;
    bool serialize;
};

}

#endif // _SIF_BASE_LOGGER_
