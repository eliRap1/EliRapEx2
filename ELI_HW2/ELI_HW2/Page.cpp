#include "Page.h"
#include <iostream>

/*
This func init the obj status and posts 
Input:none
Output: none
*/
void Page::init()
{
	this->_status = "";
	this->_posts = "";
}

/*
This func gets the posts from the page
Input:none
Output: string- the posts on the page
*/
std::string Page::getPosts() const
{
	return this->_posts;
}

/*
This func gets the status of the page
Input: none
Output: string - the current status of the page
*/
std::string Page::getStatus() const
{
	return this->_status;
}

/*
This func clears the posts, reset value.
*/
void Page::clearPage()
{
	this->_posts = "";
}

/*
This func sets the status of the page 
Input: string  the new status for the page
Output: none 
*/
void Page::setStatus(const std::string status)
{
	this->_status = status;
}

/*
This func adds a new line to the posts on the page
Input: string the line to add to the posts
Output: none 
*/
void Page::addLineToPosts(const std::string new_line)
{
	this->_posts += new_line + "\n";
}