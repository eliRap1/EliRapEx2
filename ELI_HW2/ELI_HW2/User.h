#pragma once
#include <string>
#include "DeviceList.h"
class User
{
public:
	void init(const unsigned int id, const std::string username, const unsigned int age);
	void clear();
	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const;

	//getters
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();

private:
	unsigned int _id;
	std::string _username;
	unsigned int _age;
	DevicesList _devices;
};
