//////////////////////////////////////////////////////////////////////////////
//
// <t-logger.cpp>
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

#include <sif.hpp>

using namespace sif;

int main(void)
{
    // Desactivation du mode DEBUG
    logger.startSerialize("log.txt"); // On sérialize tout dans log.txt
    logger.setQuiet(Logger::PROGRESS); // Pas de message de progression affiché
    logger.startSerialize(Logger::ERROR, "error.txt"); // On sérialize les erreurs à part
        
    // Test
    logger(Logger::PROGRESS) << "Step1 completed.";
    logger << "Step2 completed";
    logger(Logger::ERROR) << "An error has occurred.";
    logger(Logger::DEBUG) << "Entering function y.";
    logger(Logger::WARNING) << "Size invalid. Set to 0.";
    logger(Logger::INFO) << "Init IA.";
 
    return 0;
    
}

