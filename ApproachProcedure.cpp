#include "ApproachProcedure.h"

ApproachProcedure::ApproachProcedure(rapidxml::xml_node<> *x){
	this->name = x->first_node("Name")->value();
	this->desc = x->first_node("Description")->value();
	rapidxml::xml_node<> *wp_list = x->first_node("WaypointIntegratorList");
	for(rapidxml::xml_node<> *waypoint = wp_list->first_node("WaypointIntegrator") ; waypoint !=0 ; waypoint = waypoint->next_sibling()){
		this->waypoints_list.push_back(waypoint);
	}

}
