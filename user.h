#pragma once
#include <string>
#include <vector>

class User
{
	std::string login_;
	std::string password_;
	std::string name_;
public:
	User() = default;
	User(const std::string& login, const std::string& password, const std::string& name);
	~User();

	const std::string getUserLogin() const;
	const std::string getUserPassword() const;
	const std::string getUserName() const;

	void resetUserPassword(const std::string& password);
	void resetUserName(const std::string& name);
};