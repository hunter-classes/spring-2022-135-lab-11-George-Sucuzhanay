#pragma once
#include <iostream>

class Profile
{
	private:
		std::string displayname;
		std::string username;
	public:
		std::string getUserName();
		std::string getFullName();
		void setDisplayName(std::string dspn);
		Profile(std::string u, std::string d);
		Profile();
};