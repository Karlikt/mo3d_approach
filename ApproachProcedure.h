#ifndef APPROACH_PROCEDURE_H
#define APPROACH_PROCEDURE_H

#include "WaypointIntegrator.h"
#include <map>
#include <list>
#include <string>

class ApproachProcedure{
	public: //to change
		std::string name;
		std::string desc;
		std::list<WaypointIntegrator> waypoints_list;

	public:
		ApproachProcedure(rapidxml::xml_node<> *x);

};

#endif
