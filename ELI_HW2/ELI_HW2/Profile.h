#pragma once
#include <string>
#include "User.h"
#include "UserList.h"
#include "Page.h"

class Profile
{
private:
	User _user;
	Page _userPage;
	UserList _friends;
public:
	void init(User owner);
	void clear();
	
	//get
	User getOwner() const;
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;
	//set
	void setStatus(const std::string new_status);
	void addPostToProfilePage(const std::string post);
	void addFriend(const User friend_to_add);
};