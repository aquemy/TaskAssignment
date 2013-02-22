//////////////////////////////////////////////////////////////////////////////
//
// <logger.hpp>
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

#ifndef _SIF_LOGGER_
#define _SIF_LOGGER_

#include <string>

#include <SIF/utils/baseLogger.hpp>

namespace sif
{

/** Logger : Logging interface

The Logger class is based on a Chain of Responsability pattern using logging level.
It defines 5 levels of logging that can be manipulated separatly through its interface.

@see sif::BaseLogger
*/

class Logger
{
public :
    /**
     * Logger Levels
     */
    enum
    {
        INFO,
        PROGRESS,
        WARNING,
        ERROR,
        DEBUG,
    };
    
    /**
     * Constructor
     * The constructor creates a BaseLogger for each level and chains them
     */
    Logger();
    
    /**
     * Destructor
     */
    ~Logger();
    
    /**
     * Start to serialize (all levels)
     * @param _logFile Log file for serialization
     */
    void startSerialize(std::string _logFile);
    
    /**
     * Start to serialize
     * @param _level Level of logging
     * @param _logFile Log file for serialization
     */
    void startSerialize(int _level, std::string _logFile);
    
     /**
     * Start to serialize (all levels)
     */
    void stopSerialize();
    
    /**
     * Stop to serialize
     * @param _level Level of logging
     */
    void stopSerialize(int _level);
    
    /**
     * Stop writting on printing stream (all levels)
     */   
    void setQuiet();
    
    /**
     * Stop writting on printing stream
     * @param _level Level of logging
     */ 
    void setQuiet(int _level);
    
    /**
     * Start writting on printing stream (all levels)
     */    
    void setVerbose();
    
    /**
     * Start writting on printing stream
     * @param _level Level of logging
     */  
    void setVerbose(int _level);
    
    /**
     * Return the current level of log
     * @return _level Level of log
     */  
    int getCurrentLevel() const;
    
    /**
     * Set the current level of log
     * @param _level Level of log
     */  
    void setCurrentLevel(int _level);
    
    /**
     * Set the current level of log (better user interface)
     * @param _level Level of log
     */      
    Logger& operator()(int _level);
    
    friend Logger& operator<<(Logger& _logger, const std::string _msg);
        
protected :
    int currentLevel;
    BaseLogger* loggerChain;
};

static Logger logger;

}

#endif // _SIF_LOGGER_
