#ifndef WAYPOINTINTEGRATOR_H
#define WAYPOINTINTEGRATOR_H

#include "Waypoint.h"
#include <map>
#include <string>

#ifdef __linux__ 
#include <rapidxml.h>
#elif _WIN32
#include <rapidxml.hpp>
#endif

class WaypointIntegrator{
	public: //to change
		std::string name;
		std::string coding;
		std::string status;
		std::string turndir;
		std::string heightmin;
		std::string heightmax;
		std::string holdingparam;
	
	public:
		static std::map<std::string, Waypoint> waypts;
		WaypointIntegrator(rapidxml::xml_node<> *x);
		const Waypoint* getWaypoint() const;

};

#endif
