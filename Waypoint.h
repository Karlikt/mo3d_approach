#include <string>
#include <rapidxml.h>

class Waypoint{
	public: //docelowo private, ale na razie dla testow ;)
		std::string name;
		std::string type;
		double lat,lon;

	public:
		Waypoint(rapidxml::xml_node<> *x);
};
