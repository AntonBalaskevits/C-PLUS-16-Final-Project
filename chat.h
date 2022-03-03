#pragma once
#include <string>
#include <vector>
#include <memory>
#include "message.h"
#include "user.h"

class Chat
{
	std::vector<User> v_users_; // container for registered users
	std::vector<User> v_login_; // container for loged in users
	std::unique_ptr<Message> ptr_message_from_; // smart pointer for messages

	std::string login_;
	std::string password_;
	std::string from_;
	std::string to_;
	std::string name_;
	std::string message_;
	std::string user_;

public:
	Chat() = default;
	~Chat();
	void RegisterNewUser();
	void UserLogin(const std::string& login, const std::string& password);
	void UserLogout(const std::string& login, const std::string& password);
	void ChatInfo();
	void sendingMessages();
	void startChat();
	bool Switch();
	bool ChatOnSwitch();
	void Menu();
};
