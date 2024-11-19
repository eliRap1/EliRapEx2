#include "Device.h"
#include <iostream>

/*
This func init the Device 
The device is set to active
Input: unsigned int id: the ID of the device
DeviceType type: the type of the device 
string os: the os of the device
Output: none
*/
void Device::init(const unsigned int id, const DeviceType type, const std::string os)
{
	this->_active = true;
	this->_id = id;
	this->_os = os;
	this->_type = type;
}

/*
This func checks if the device is active
Input:none
Output: bool - true if the device is active
*/
bool Device::isActive() const
{
	return this->_active;
}

/*
This func activates the device
Input:none
Output: none
*/
void Device::activate()
{
	this->_active = true;
}
/*
This func deactivates  the device*/
void Device::deactivate()
{
	this->_active = false;
}

/*
This func deactivates the device*/
std::string Device::getOS() const
{
	return this->_os;
}

/*
This func gets the op of the device
Input:none
Output: string - the os of the device
*/
DeviceType Device::getType() const
{
	return this->_type;
}

/*
This function gets the type of the device*/
unsigned int Device::getID() const
{
	return this->_id;
}