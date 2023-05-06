#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>

class Exchange
{	
	public:
		Exchange();
		Exchange(const Exchange &toCopy);
		~Exchange();
	private:
		std::map<std::string, int> values;
		Exchange &operator=(const Exchange &toCopy);
};