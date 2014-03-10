#include "Waypoint.h"
#include <cstdlib>

Waypoint::Waypoint(rapidxml::xml_node<> *x){
	this->name = x->first_node("Name")->value();
	this->type = x->first_node("Type")->value();
	this->lat = std::atof(x->first_node("Latitude")->value());
	this->lon = std::atof(x->first_node("Longitude")->value());
}
