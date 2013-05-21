//////////////////////////////////////////////////////////////////////////////
//
// <ut-kuhn.cpp>
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

#include <exception>

#include <sif.hpp>

using namespace std;
using namespace sif;

int cinq (int i, double _time)
{ return 5; }

int main(void)
{
    /**
     * Unit tests for kuhn
     */
    try
    {
    	// Creation of some resource for the tests
    	AStar spa;
        Coordonate<2,int> coord1, coord2, coord3, coord4, coord5;
        coord1[0] = 0;   coord1[1] = 0;
        coord2[0] = 5;   coord2[1] = 5;
        coord3[0] = 1;   coord3[1] = 0;
        coord4[0] = 5;   coord4[1] = 6;
        coord5[0] = 10;   coord5[1] = 10;
        
    	AResource* r1 = new Resource<2,int,int>(coord1, 100, false, spa);
    	AResource* r2 = new Resource<2,int,int>(coord2, 100, false, spa);
    	
    	Task t, s, u;
        ATaskSpot* ts1 = new TaskSpot<2,int>(coord3, t, cinq);
        ATaskSpot* ts2 = new TaskSpot<2,int>(coord4, s, cinq);
        ATaskSpot* ts3 = new TaskSpot<2,int>(coord5, u, cinq);
    	
    	std::pair<AResource*, ATaskSpot*> p_r1ts1, p_r1ts2, p_r1ts3, p_r2ts1, p_r2ts2, p_r2ts3;
    	p_r1ts1 = std::make_pair(r1, ts1);
    	p_r1ts2 = std::make_pair(r1, ts2);
    	p_r1ts3 = std::make_pair(r1, ts3);
    	p_r2ts1 = std::make_pair(r2, ts1);
    	p_r2ts2 = std::make_pair(r2, ts2);
    	p_r2ts3 = std::make_pair(r2, ts3);
    	std::map<std::pair<AResource*, ATaskSpot*>, int> map;
    	
    	
    	// 1- Test with 1 resource & 1 taskSpot
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r1ts1, 1));
    	std::map<AResource*,ATaskSpot*> res, wantedRes;
    	
    	Kuhn k;
    	res = k.operator()(map);
    	wantedRes.insert(std::pair<AResource*,ATaskSpot*>(r1, ts1));
    	if(res != wantedRes)
            throw runtime_error("Error in expectations for first test");
            
        // 2- Test with 2 resource & 2 taskSpot
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r1ts2, 5));
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r2ts1, 4));
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r2ts2, 1));
        
    	res = k.operator()(map);
    	wantedRes.insert(std::pair<AResource*,ATaskSpot*>(r2, ts2));
		
    	if(res != wantedRes)
		    throw runtime_error("Error in expectations for second test");
            
        // 3- Test with 2 resource & 3 taskSpot
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r1ts3, 6));
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r2ts3, 3));
        
    	res = k.operator()(map);
		
    	if(res != wantedRes)
		    throw runtime_error("Error in expectations for third test");
            
        // 4- Test with 2 resource & 1 taskSpot
    	map.clear();
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r1ts1, 1));
    	map.insert(std::pair<std::pair<AResource*, ATaskSpot*>, int> (p_r2ts1, 4));
        
    	res = k.operator()(map);
    	wantedRes.clear();
    	wantedRes.insert(std::pair<AResource*,ATaskSpot*>(r1, ts1));
		
    	if(res != wantedRes)
		    throw runtime_error("Error in expectations for fourth test");
        
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }
    
    return 0;
    
}

