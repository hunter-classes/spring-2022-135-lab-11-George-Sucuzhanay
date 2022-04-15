#include "profile.h"
#include <iostream>

Profile::Profile()
{
    username = "";
    displayname = "";
}
Profile::Profile(std::string a, std::string b){
    username = a;
    displayname = b;
}
std::string Profile::getUserName()
{
    return username;
}
std::string Profile::getFullName()
{
    return displayname + " (@" + username + ")";
}
void Profile::setDisplayName(std::string d)
{
    displayname = d;
}
