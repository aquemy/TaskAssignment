//////////////////////////////////////////////////////////////////////////////
//
// <logger.cpp>
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

#include <SIF/utils/logger.hpp>

namespace sif
{

Logger::Logger()
{
    loggerChain = new BaseLogger(Logger::INFO, "INFO");
    BaseLogger* p = loggerChain;
    p = p->setNext(new BaseLogger(Logger::PROGRESS, "PROG"));
    p = p->setNext(new BaseLogger(Logger::WARNING, "WARN"));
    p = p->setNext(new BaseLogger(Logger::ERROR, "ERROR", std::cerr));
    p = p->setNext(new BaseLogger(Logger::DEBUG, "DEBUG"));
}
    
Logger::~Logger()
{
    BaseLogger* p = loggerChain;
    BaseLogger* q = p;
    while(p != nullptr)
    {
        p = p->getNext();
        delete q;
        q = p;
    }
}
    
void Logger::startSerialize(std::string _logFile)
{
    loggerChain->startSerialize(_logFile);
}
    
void Logger::startSerialize(int _level, std::string _logFile)
{
    loggerChain->startSerialize(_level, _logFile);
}
    
void Logger::stopSerialize()
{
    loggerChain->stopSerialize();
}
    
void Logger::stopSerialize(int _level)
{
    loggerChain->stopSerialize(_level);
}
    
void Logger::setQuiet()
{
    loggerChain->setQuiet();
}
    
void Logger::setQuiet(int _level)
{
    loggerChain->setQuiet(_level);
}
    
void Logger::setVerbose()
{
    loggerChain->setVerbose();
}
    
void Logger::setVerbose(int _level)
{
    loggerChain->setVerbose(_level);
}
    
void Logger::setStatus(int _level, bool _quiet)
{
    loggerChain->setStatus(_level, _quiet);
}
    
int Logger::getCurrentLevel() const
{
    return currentLevel;
}
    
void Logger::setCurrentLevel(int _level)
{
    currentLevel = _level;
}
        
Logger& Logger::operator()(int _level)
{
    setCurrentLevel(_level);
    return *this;
}
    
Logger& operator<<(Logger& _logger, const std::string _msg)
{
    _logger.loggerChain->handle(_msg, _logger.getCurrentLevel());
}

}

