#include "SocialNetwork.h"
#include <iostream>

#define WINDOWS7 "Windows7"
#define WINDOWS10 "Windows10"
#define WINDOWS11 "Windows11"
/*
This func init the obj
Input:string the name of the social network, int - the min age 
Output: none
*/
void SocialNetwork::init(const string networkName, const int minAge)
{
	this->_minAge = minAge;
	this->_networkName = networkName;
	this->_profiles.init();
}

/*
This func clears the class, reset all values.
*/
void SocialNetwork::clear()
{
	this->_minAge = 0;
	this->_networkName = "";
	this->_profiles.clear();
}

/*
This func gets the name of the social network
Input: none
Output: string - the name of the social network
*/
string SocialNetwork::getNetworkName() const
{
	return this->_networkName;
}

/*
This func  gets the min age
Input:none
Output: int- the minimum age for profiles
*/
int SocialNetwork::getMinAge() const
{
	return this->_minAge;
}


/*
This func gets all Windows devices
Input: none
Output: string - containes Windows devices and id
*/
string SocialNetwork::getWindowsDevices() const
{
	string allWindow = "";
	string windowsOS = "";
	ProfileNode* temp = this->_profiles.get_first();
	DeviceNode* devices = nullptr;
	while (temp)
	{
		devices = temp->get_data().getOwner().getDevices().get_first();
		while (devices)
		{
			windowsOS = devices->get_data().getOS();
			if (windowsOS == WINDOWS10 || windowsOS == WINDOWS11 || windowsOS == WINDOWS7)
			{
				allWindow += "[" + std::to_string(devices->get_data().getID()) + ", " + devices->get_data().getOS() + "], ";

			}
			devices = devices->get_next();
		}
		temp = temp->get_next();
	}
	delete devices;
	delete temp;

	allWindow.erase(allWindow.length() - 2);
	return allWindow;
}

/*
This func adds a profile to the social network if the profileis in the min age
Input:  Profile - the profile to be added to the network.
Output: bool - true if the profile was added, false if the owner does not old enough
*/
bool SocialNetwork::addProfile(const Profile profile_to_add)
{
	bool ofAge = true;
	if (profile_to_add.getOwner().getAge() < this->_minAge)
	{
		ofAge = false;
	}
	else
	{
		this->_profiles.add(profile_to_add);
	}
	return ofAge;
}