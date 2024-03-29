//////////////////////////////////////////////////////////////////////////////
//
// <baseLogger.hpp>
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

#ifndef _SIF_BASE_LOGGER_
#define _SIF_BASE_LOGGER_

#include <iostream>
#include <string>

namespace sif
{

/** BaseLogger : Element of the reponsability chain of logging

The BaseLogger class define an element of the logger. It defines a level of logging
and have two streams, one for printing and one for serialize logs in a specified file.

@see sif::Logger
*/

class BaseLogger
{
public:
    /**
     * Constructor
     * @param _level Level of logging
     * @param _label Label of the level
     * @param _os Printing stream
     * @param _quiet Quiet mode
     */
    BaseLogger(int _level, std::string _label, std::ostream& _os = std::clog, bool _quiet = false);
    
    /**
     * Constructor
     * @param _level Level of logging
     * @param _label Label of the level
     * @param _logFile Log file for serialization
     * @param _os Printing stream
     * @param _quiet Quiet mode
     */
    BaseLogger(int _level, std::string _label,  std::string _logFile, std::ostream& _os = std::clog, bool _quiet = false);
    
    /**
     * Destructor
     */
    ~BaseLogger();
 
    /**
     * Set next element in reponsability chain
     * @param _next Pointer on next element
     * @return This element
     */
    BaseLogger* setNext(BaseLogger* _next);
    
    /**
     * Get next element in reponsability chain
     * @return Pointer on next element
     */
    BaseLogger* getNext() const;
 
    /**
     * Try to handle the message
     * @param _msg Message to handle
     * @param _priority Level of the message
     */
    void handle(const std::string _msg, int _priority);
    
    /**
     * Start to serialize
     * @param _level Level of logging
     * @param _logFile Log file for serialization
     */
    void startSerialize(int _level, std::string _logFile);
    
    /**
     * Start to serialize (all levels)
     * @param _logFile Log file for serialization
     */
    void startSerialize(std::string _logFile);
    
    /**
     * Stop to serialize
     * @param _level Level of logging
     */
    void stopSerialize(int _level);
    
    /**
     * Start to serialize (all levels)
     */
    void stopSerialize();
     
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
     * Print message on the specified stream
     * @param _msg Message to write
     * @param _stream Stream
     */     
    void print(const std::string _msg, std::ostream* _stream);
    
    /**
     * Log the message and dispatch on streams
     * @param _msg Message to log
     */ 
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

