#include "User.h"
#include <iostream>

/*
This func init the User with id, username, age, and an empty devices 
Input:
 unsigned int id: the id of the user
 string username: the username of the user
 unsigned int age: the age of the user
Output:none
*/
void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
	this->_devices.init();
}

/*
This func clears the posts, reset value.
*/
void User::clear()
{
	this->_devices.clear();
	this->_id = 0;
	this->_username = "";
	this->_age = 0;
}

/*
This func gets the user id
Input:none
Output: unsigned int: the id of the user
*/
unsigned int User::getID() const
{
	return this->_id;
}

/*
This func gets the users username
Input: none
Output: string: the username of the user
*/
std::string User::getUserName() const
{
	return this->_username;
}

/*
This func getsthe users age
Input:none
Output: unsigned int: the age of the user
*/
unsigned int User::getAge() const
{
	return this->_age;
}


/*
This func gets the devices list 
Input:none
Output: DevicesList&: a reference to the users devices list
*/
DevicesList& User::getDevices() 
{
	return this->_devices;
}

/*
This func adds a new device to the users devices list
Input: Device newDevice: the device to add to the users
Output:none
*/
void User::addDevice(const Device newDevice)
{
	this->_devices.add(newDevice);
}

/*
This func checks if all the users devices are active
Input:none
Output: bool: true if all devices are active
*/
bool User::checkIfDevicesAreOn() const
{
	bool isOn = true;
	DeviceNode* temp = this->_devices.get_first();
	while (temp)
	{
		if (temp->get_data().isActive() == false)
		{
			isOn = false;
		}
		temp = temp->get_next();
	}
	delete temp;
	return isOn;
}