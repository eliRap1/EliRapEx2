#include "Profile.h"
#include <iostream>
using std::endl;
using std::cout;

/*
This func init the Profile owner, an empty user page, and an empty friends list
Input: User owner: the owner of the profile
Output: none
*/
void Profile::init(User owner)
{
	this->_user = owner;
	this->_userPage.init();
	this->_friends.init();
}

/*
This func clears the profile user page and friends list
*/
void Profile::clear() 
{
	this->_userPage.clearPage();
	this->_friends.clear();
}

/*
This func adds a post to the profile page
Input: string post: the post to be added
Output:none
*/
void Profile::addPostToProfilePage(const std::string post)
{
	this->_userPage.addLineToPosts(post);
}

/*
This func adds a friend to the profile's friends list
Input: User friend_to_add: the friend to be added
Output:none
*/
void Profile::addFriend(const User friend_to_add)
{
	this->_friends.add(friend_to_add);
}

/*
This func gets the owner of the profile
Input:none
Output: User: the owner of the profile
*/
User Profile::getOwner() const
{
	return this->_user;
}

/*
This func gts the entire profile page, the status and posts
Input:none
Output: string: the content of the profile page
*/
std::string Profile::getPage() const
{
	std::string allPage = "Status: " + this->_userPage.getStatus();
	allPage += "\n*******************\n*******************\n";
	allPage += this->_userPage.getPosts();
	return allPage;
}

/*
This func gets the names of all friends in the profile's friends list
Input:none
Output: string: a comma-separated list of friends' names
*/
std::string Profile::getFriends() const 
{
	UserNode* temp = this->_friends.get_first();
	std::string allFriends = "";
	while (temp)
	{
		allFriends += temp->get_data().getUserName();
		if (temp->get_next())
		{
			allFriends += ",";
		}
		temp = temp->get_next();
	}
	delete temp;
	return allFriends;

}

/*
This func gets the names of all friends with usernames of the same length as the owner username
Input:none
Output: string: friends names with the same username length as the owner
*/
std::string Profile::getFriendsWithSameNameLength() const
{
	UserNode* temp = this->_friends.get_first();
	unsigned int lenOfOwner = this->_user.getUserName().length();
	std::string allFriendsAndLength = "";
	std::string name = "";
	while (temp)
	{
		name = temp->get_data().getUserName();
		if (name.length() == lenOfOwner)
		{
			allFriendsAndLength += name;
			if (temp->get_next() && temp->get_next()->get_data().getUserName().length() == lenOfOwner)
			{
				allFriendsAndLength += ",";
			}
		}
		temp = temp->get_next();
	}
	delete temp;
	return allFriendsAndLength;
}

/*
This func sets a new status for the profile page.
Input: string new_status: the new status to be set
Output:none
*/
void Profile::setStatus(const std::string new_status)
{
	this->_userPage.setStatus(new_status);
}
