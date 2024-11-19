#pragma once
#include "ProfileList.h"
using std::string;
class SocialNetwork
{
public:
	void init(const string networkName, const int minAge);
	void clear();

	//get
	string getNetworkName() const;
	int getMinAge() const;
	string getWindowsDevices() const;
	//set
	bool addProfile(const Profile profile_to_add);
private:
	string _networkName;
	int _minAge;
	ProfileList _profiles;
};

