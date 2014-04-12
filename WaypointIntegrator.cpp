#include "WaypointIntegrator.h"

std::map<std::string, Waypoint> WaypointIntegrator::waypts;

WaypointIntegrator::WaypointIntegrator(rapidxml::xml_node<> *x){
	this->name = x->first_node("Name")->value();
	this->coding = x->first_node("Coding")->value();
	this->status = x->first_node("Status")->value();
	this->turndir = x->first_node("TurnDirection")->value();
	this->heightmin = x->first_node("HeightMin")->value();
	this->heightmax = x->first_node("HeightMax")->value();
	this->holdingparam = x->first_node("HoldingParam0")->value();
}

const Waypoint * WaypointIntegrator::getWaypoint() const{
	std::map<std::string, Waypoint>::iterator i;
	i = waypts.find(this->name);
	if(i==waypts.end()) return NULL;
	else return &(i->second);
}

