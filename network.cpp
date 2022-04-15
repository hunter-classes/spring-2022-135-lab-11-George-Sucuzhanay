#include "network.h"
#include <iostream>
#include <string>
#include <cctype>

Network::Network()
{
    numUsers = 0;
    for(int i = 0; i < MAX_USERS; i++){
        for(int j = 0; i < MAX_USERS; j++)
        {
            following[i][j] = false;
        }
    }
}

int Network::findID(std::string username){
    for(int i = 0; i < numUsers; i++){
        if(profiles[i].getUserName() == username){
            return i;
        }
    }
    return -1;
}
bool Network::addUser(std::string usern, std::string displayN){
    if (numUsers >= MAX_USERS)
		return false;
	profiles[numUsers++] = {usern, displayN};
	return true;
}
bool Network::follow(std::string usernameOne, std::string usernameTwo){
    int follower = findID(usernameOne);
    int follwerTwo = findID(usernameTwo);
    if(usernameOne != usernameTwo && follwerTwo != -1 && follower != -1){
        following[follower][follwerTwo] = true;
    }
    return following[follower][follwerTwo];
}
void Network::printDot()
{
    std::cout << "digraph {" << std::endl;
	for (int i = 0; i < numUsers; i++)
		std::cout << "\t\"@" << profiles[i].getUserName() << "\"" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < numUsers; i++)
	{
		for (int j = 0; j < numUsers; j++)
		{
			if (following[i][j])
				std::cout << "\t\"@" << profiles[i].getUserName() << "\" -> \"@" << profiles[j].getUserName() << "\"" << std::endl;
		}
	}
	std::cout << "}" << std::endl;
}

// digraph {
//   "@mario"
//   "@luigi"
//   "@yoshi"

//   "@mario" -> "@luigi"
//   "@luigi" -> "@mario"
//   "@luigi" -> "@yoshi"
//   "@yoshi" -> "@mario"
// }
