#include <string>
#ifdef __linux__ 
#include <rapidxml.h>
#elif _WIN32
#include <rapidxml.hpp>
#endif

class Waypoint{
	public: //docelowo private, ale na razie dla testow ;)
		std::string name;
		std::string type;
		double lat,lon;

	public:
		Waypoint(rapidxml::xml_node<> *x);
};
