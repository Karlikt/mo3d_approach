#include <cstdio>
#include <iostream>
#include <fstream>
#ifdef __linux__ 
#include <rapidxml.h>
#include <rapidxml_print.h>
#elif _WIN32
#include <rapidxml.hpp>
#include <rapidxml_print.hpp>
#endif

#include "WaypointIntegrator.h"
#include "Waypoint.h"
#include "ApproachProcedure.h"

int main(int argc, char *argv[]){
	char *filename = "EPKT_scenario.xml";
	int filesize = 0;
	char *xmldoc;

	if(argc>1)
	{
		filename = argv[1];
	}
	std::ifstream input(filename, std::ios::in | std::ios::binary);

	input.seekg(0, std::ios::end);
	
	filesize = (int)input.tellg();

	input.seekg(0, std::ios::beg);

	xmldoc = new char[filesize+1];

	input.read(xmldoc, filesize);
	xmldoc[filesize]=0;


	rapidxml::xml_document<> doc;
	doc.parse<0>(xmldoc);

	std::cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

	rapidxml::xml_node<> *wp_list = doc.first_node()->first_node("WaypointList");
	rapidxml::xml_node<> *app_list = doc.first_node()->first_node("ApproachProcedureList");

	for(rapidxml::xml_node<> *waypoint = wp_list->first_node("Waypoint") ; waypoint != 0 ; waypoint = waypoint->next_sibling())
	{
//		std::cout << waypoint->first_node("Name")->value() << ": " << waypoint->first_node("Type")->value() << " coords " << waypoint->first_node("Latitude")->value() << ";" << waypoint->first_node("Longitude")->value() << std::endl;
		Waypoint temp(waypoint);
		WaypointIntegrator::waypts.insert(std::pair<std::string, Waypoint>(temp.name, temp));
	}
	for(std::map<std::string, Waypoint>::iterator itek = WaypointIntegrator::waypts.begin() ; itek != WaypointIntegrator::waypts.end() ; itek++){
		std::cout << itek->second.name << ": " << itek->second.type << " coords " << itek->second.lat << ";" << itek->second.lon << std::endl;
	}
	for(rapidxml::xml_node<> *app = app_list->first_node("ApproachProcedure") ; app != 0 ; app = app->next_sibling())
	{
		ApproachProcedure temp(app);
		std::cout 
			<< temp.name << std::endl
			<< temp.desc << std::endl
			<< temp.waypoints_list.begin()->name << std::endl
			<< temp.waypoints_list.begin()->getWaypoint()->lat << "," << temp.waypoints_list.begin()->getWaypoint()->lon << std::endl
			<< (++temp.waypoints_list.begin())->name << std::endl
			<< (++temp.waypoints_list.begin())->getWaypoint()->lat << "," << (++temp.waypoints_list.begin())->getWaypoint()->lon << std::endl
			<< std::endl;
	}
#if _WIN32
	system("pause");
#endif
}
