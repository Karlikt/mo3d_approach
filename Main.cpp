#include <cstdio>
#include <iostream>
#include <fstream>
#include <rapidxml.h>


#include <rapidxml_print.h>


#include "Waypoint.h"

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
	
	filesize = input.tellg();

	input.seekg(0, std::ios::beg);

	xmldoc = new char[filesize];

	input.read(xmldoc, filesize);


	rapidxml::xml_document<> doc;
	doc.parse<0>(xmldoc);

	std::cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

	rapidxml::xml_node<> *wp_list = doc.first_node()->first_node("WaypointList");
	rapidxml::xml_node<> *app_list = doc.first_node()->first_node("ApproachProcedureList");

	//rapidxml::print(std::cout, *wp_list, 0);
	//rapidxml::print(std::cout, *app_list, 0);
	for(rapidxml::xml_node<> *waypoint = wp_list->first_node("Waypoint") ; waypoint != 0 ; waypoint = waypoint->next_sibling())
	{
//		std::cout << waypoint->first_node("Name")->value() << ": " << waypoint->first_node("Type")->value() << " coords " << waypoint->first_node("Latitude")->value() << ";" << waypoint->first_node("Longitude")->value() << std::endl;
		Waypoint temp(waypoint);
		std::cout << temp.name << ": " << temp.type << " coords " << temp.lat << ";" << temp.lon << std::endl;
	}

}
