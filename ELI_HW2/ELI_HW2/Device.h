#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*									    //
	Those definitions are used for tests,               //
	you can add your own, but please do not delete any. //
*/									    //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		    //
									    //
#define UbuntuOS "UbuntuLinux"                            //						
#define RedHatOS "RedHatLinux"				    //
#define MacOS "MacOS"						    //
#define IOS "IOS"							    //
#define WINDOWS7 "Windows7"                               //
#define WINDOWS10 "Windows10"                             //
#define WINDOWS11 "Windows11"                             //
#define ANDROID "Android"                                 //
									    //
/// ///////////////////////////////////////////////////////

class Device
{
private:
	unsigned int _id;
	std::string _os;
	DeviceType _type;
	bool _active;

public:
	void init(const unsigned int id, const DeviceType type, const std::string os);

	//getters
	std::string getOS() const;
	int unsigned getID() const;
	DeviceType getType() const;

	bool isActive() const;
	void activate();
	void deactivate();
};
