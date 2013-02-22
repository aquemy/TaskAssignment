//////////////////////////////////////////////////////////////////////////////
//
// <baseLogger.cpp>
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

#include <fstream>
#include <algorithm>
#include <iomanip>

#include <SIF/utils/baseLogger.hpp>
#include <SIF/utils/timeManagement.hpp>

namespace sif
{

BaseLogger::BaseLogger(int _level, std::string _label, std::ostream& _os, bool _quiet) :
        level(_level),
        next(nullptr),
        os(&_os),
        quiet(_quiet),
        logFile(""),
        of(nullptr),
        serialize(false)
    {
        std::transform(_label.begin(), _label.end(), _label.begin(), (int (*)(int))std::toupper);
        label = _label.substr(0,5);
    };
    
BaseLogger::BaseLogger(int _level, std::string _label,  std::string _logFile, std::ostream& _os
, bool _quiet) :
        BaseLogger(_level,_label, _os, _quiet)
    {
        logFile = _logFile;
        of = new std::ofstream(logFile, std::ios_base::ate | std::ios_base::app);
        serialize = true;
    }
    
BaseLogger::~BaseLogger()
    {
        delete of;
    }
 
BaseLogger* BaseLogger::setNext(BaseLogger* _next)
    {
        next = _next;
        return getNext();
    }
        
BaseLogger* BaseLogger::getNext() const
    {
        return next;
    }
 
    void BaseLogger::handle(const std::string msg, int priority)
    {
        if (priority <= level)
            *this << msg;
        else if (next != nullptr)
            next->handle(msg, priority);
    }
    
    void BaseLogger::startSerialize(int _level, std::string _logFile)
    {
        if (_level <= level)
        {
            if(!_logFile.empty())
            {
                if(logFile != _logFile)
                {
                    logFile = _logFile;
                    if(of != nullptr)
                        delete of;
                        
                    of = new std::ofstream(logFile, std::ios_base::ate | std::ios_base::app);
                    serialize = true;
                }
            }
        }
        else if (next != nullptr)
            next->startSerialize(_level, _logFile);
    }
    
    void BaseLogger::startSerialize(std::string _logFile)
    {
        if(!_logFile.empty())
        {
            if(logFile != _logFile)
            {
                logFile = _logFile;
                if(of != nullptr)
                    delete of;
                        
                of = new std::ofstream(logFile, std::ios_base::ate | std::ios_base::app);
                serialize = true;
            }
        }
        if (next != nullptr)
            next->startSerialize(_logFile);
    }
    
    void BaseLogger::stopSerialize(int _level)
    {
        if (_level <= level)
            serialize = false;
        else if (next != nullptr)
            next->stopSerialize(_level);
    }
    
    void BaseLogger::stopSerialize()
    {
        serialize = false; 
        if (next != nullptr)
            next->stopSerialize();
    }
        
    void BaseLogger::setQuiet()
    {
        quiet = true;
        if (next != nullptr)
            next->setQuiet();
    }
    
    void BaseLogger::setQuiet(int _level)
    {
        if (_level <= level)
            quiet = true;
        else if (next != nullptr)
            next->setQuiet(_level);
    }
        
    void BaseLogger::setVerbose()
    {
        quiet = false;
        if (next != nullptr)
            next->setVerbose();
    }
    
    void BaseLogger::setVerbose(int _level)
    {
        if (_level <= level)
            quiet = false;
        else if (next != nullptr)
            next->setVerbose(_level);
    }
        
    void BaseLogger::setStatus(int _level, bool _status)
    {
        if (_level <= level)
            quiet = _status;
        else if (next != nullptr)
            next->setStatus(_level, _status);
    }
        
    void BaseLogger::print(const std::string _msg, std::ostream* _stream)
    {
        *_stream << currentTime()
           << " - ["
           << std::setw (5)
           << std::setiosflags (std::ios::right)
           << label
           << "] : "
           << _msg 
           << std::endl;
    }
    
    void BaseLogger::log(std::string _msg)
    {
        if(!quiet)
            print(_msg, os);
        if(serialize && of != nullptr)
            print(_msg, of);
    }
 
    BaseLogger& operator<<(BaseLogger& _logger, const std::string _msg)
    {
        _logger.log(_msg);
    }

}
