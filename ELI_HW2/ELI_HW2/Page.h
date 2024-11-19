#pragma once
#include <string>

class Page
{
public:
	void init();
	std::string getPosts() const;
	std::string getStatus() const;
	void clearPage();
	void setStatus(const std::string status);
	void addLineToPosts(const std::string new_line);
private:
	std::string _status;
	std::string _posts;
};