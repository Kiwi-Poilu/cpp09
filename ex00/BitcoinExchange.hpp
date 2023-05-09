#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <exception>
#include <typeinfo>

class Exchange
{	
	public:
		Exchange();
		Exchange(const Exchange &toCopy);
		~Exchange();
	private:
		std::map<std::string, float> values;
		Exchange &operator=(const Exchange &toCopy);
};