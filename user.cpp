#include "user.h"

User::User(const std::string& login, const std::string& password, const std::string& name)
	: login_(login), password_(password), name_(name) {}

User::~User() {}

const std::string User::getUserLogin() const
{
	return login_;
}
const std::string User::getUserPassword() const
{
	return password_;
}
const std::string User::getUserName() const
{
	return name_;
}

void User::resetUserPassword(const std::string& password)
{
	password_.erase();
	password_ = password;
}
void User::resetUserName(const std::string& name)
{
	name_.erase();
	name_ = name;
}
