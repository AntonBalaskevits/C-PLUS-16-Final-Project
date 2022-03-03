#include "chat.h"
#include <iostream>

Chat::~Chat() {}

void Chat::RegisterNewUser()
{
	bool found = false;

	do // first step login check
	{
		std::cout << "enter your login here     : ";
		std::cin >> login_;
		std::cout << "enter your password here  : ";
		std::cin >> password_;
		std::cout << "enter your user name here : ";
		std::cin >> name_;

		for (auto i = 0; i < v_users_.size(); ++i) // checks if users login is already registered
		{
			if (v_users_.size() == 0) // checks if vector container has zero elements
			{
				found = false; 
				break;
			}
			else if (login_ == v_users_[i].getUserLogin()) // if login is already registered goes in do loop again
			{
				found = true;
				std::cout << "user whit this login is already registred!" << std::endl;
				std::cout << "please choose another login." << std::endl;
				break;
			}
			else
			{
				found = false; // found is false if all cycles of for loop did not match any conditions above, and finisches do loop code block
			}
		}

	} while (found);

	User newUser(login_, password_, name_); // creates new user for registration
	v_users_.push_back(newUser);
	static int userCountIndex = 0; // static here is only used to find user that was recently registerd and cout to console

	std::cout << "user : " << v_users_[userCountIndex].getUserName();
	std::cout << " is successfully registered!" << std::endl;

	++userCountIndex; // after user was registered increments by one, so next time when new user is registered userCountIndex will point to a last user registered
}
void Chat::UserLogin(const std::string& login, const std::string& password)
{
	bool found = false; // found is used as checkpoint to track the exception

	for (auto i = 0; i < v_users_.size(); ++i)
	{
		if ((login == v_users_[i].getUserLogin()) && (password == v_users_[i].getUserPassword())) // login password check
		{
			found = true;
			User userLogin(v_users_[i].getUserLogin(), v_users_[i].getUserPassword(), v_users_[i].getUserName()); // vector container for login that keeps all registered user
			v_login_.push_back(userLogin);
			break;
		}
	}
	if (!found) // if found is false it will throw exception, other-wise means that login was successull
	{
		throw "password or login is not matching current data of registered users!";
	}

	for (auto i = 0; i < v_login_.size(); ++i) // for loop just to find and cout to a console that user was successfully loged in
	{
		if ((login == v_login_[i].getUserLogin()) && (password == v_login_[i].getUserPassword()))
		{
			std::cout << "user : " << v_login_[i].getUserName() << " is loged in." << std::endl;
		}
	}
}
void Chat::UserLogout(const std::string& login, const std::string& password)
{
	bool found = false; // same checkpoint as in other blocks of code for exceptions

	for (auto i = 0; i < v_login_.size(); ++i)
	{
		if (login == v_login_[i].getUserLogin() && password == v_login_[i].getUserPassword())
		{
			found = true;
			v_login_.erase(v_login_.begin() + i); // when found erases users from vector container for logins
		}
	}
	if (!found)
	{
		throw "password or login is not matching current data of registerd users!";
	}
}
void Chat::ChatInfo()
{
	std::cout << "\n";
	std::cout << "              info" << std::endl;
	std::cout << "current number of registered users : " << v_users_.size() << std::endl;
	std::cout << "current number of users loged in   : " << v_login_.size() << std::endl;
	std::cout << "user names : ";

	for (auto i = 0; i < v_users_.size(); ++i)
	{
		std::cout << v_users_[i].getUserName() << " "; // couts users alla registered users names
	}
	std::cout << "\n";
}
void Chat::sendingMessages()
{
	bool on = true; // variable for main chat loop
	bool found = false; // variable is used for if(condition checks) for checkpoints
	int nameIndex = 0; // variable is used as index for iterating in vector to find User objects 

	while (on)
	{
		std::cout << "login          : ";
		std::cin >> login_;
		std::cout << "password       : ";
		std::cin >> password_;
		std::cout << "write message  : ";
		std::cin >> message_;
		std::cout << "recipient name : ";
		std::cin >> to_;

		for (auto i = 0; i < v_users_.size(); ++i) // 1st block. write message block
		{
			if (login_ == v_users_[i].getUserLogin() && password_ == v_users_[i].getUserPassword())
			{
				found = true;
				nameIndex = i; // value of (i) here is just an index in vector-
				break;         // -to find object that belongs to a login and password in registred users 
			}                  // so it can be used in next block of code down below!
		}
		if (!found) // exception generated if password and login is not matching registred users in vector_container
		{
			throw "ERROR: login/password is not matching current data of registered users!";
		}

		std::unique_ptr<Message> new_message_from_(new Message(message_, v_users_[nameIndex].getUserName(), to_)); // creates message

		if (to_ == "all") // 2 block. checks if message is addressed to all users
		{
			std::cout << "message        : " << new_message_from_->getMessage() << std::endl;
			std::cout << "message from   : " << v_users_[nameIndex].getUserName() << " is addressed to ALL!" << std::endl;

			for (auto i = 0; i < v_users_.size(); ++i) // skips the sender, to avoid his name being couted to console
			{
				if (login_ == v_users_[i].getUserLogin() && password_ == v_users_[i].getUserPassword())
				{
					continue;
				}
				else
				{
					std::cout << v_users_[i].getUserName() << std::endl;
				}
			}
			on = Switch(); // simple func to check if users wants to keep sending messages
		}
		else
		{
			for (auto i = 0; i < v_users_.size(); ++i) // 3d block. for sending messages to a specific user
			{
				if (to_ == v_users_[i].getUserName()) // checks if name of the recipient matches currently registered users
				{
					found = true;
					break;
				}
				else
				{
					found = false;
				}
			}
			if (!found) // will be thrown if there is no match whit registered users
			{
				throw "ERROR: there is no recipient registered whit this user name!";
			}

			for (auto i = 0; i < v_users_.size(); ++i) // send message 
			{
				if (to_ == v_users_[i].getUserName()) // finds registred user and moves unique_ptr to a new unique_ptr field
				{
					ptr_message_from_ = std::move(new_message_from_);
					break;
				}
			}

			std::cout << "message recived!" << std::endl;
			std::cout << "from      : " << ptr_message_from_->getFrom() << std::endl; // shows from who the message is send
			std::cout << "recipient : " << ptr_message_from_->getTo() << std::endl; // shows to who message is send

			std::cout << "to read message please enter login and password" << std::endl;
			std::cout << "login     : ";
			std::cin >> login_;
			std::cout << "password  : ";
			std::cin >> password_;

			found = false; // reseting found condition before final code block of the chat for exception

			for (auto i = 0; i < v_users_.size(); ++i) // reading the message block, 4th and final block of message cycle
			{
				if (login_ == v_users_[i].getUserLogin() && password_ == v_users_[i].getUserPassword())
				{
					found = true;
					std::cout << "message   : " << ptr_message_from_->getMessage() << std::endl; // couts message if login and password matches recipient credentials
				}
			}
			if (!found)
			{
				throw "ERROR: login/password is not matching recipient name!";
			}

			on = Switch(); // final check of chat loop. if Switch returns false,chat loop breaks and returns to main
		}

		ptr_message_from_.release(); // realising the message object after one iteration of a chat flow

	}
}
void Chat::startChat()
{
	bool found = false; // for checkpoints
	bool chatOn = true; // fo main while loop

	std::cout << "        Welcome to live chat!" << std::endl;
	std::cout << "please login and enter your password" << std::endl;
	std::cout << "login          : ";
	std::cin >> login_;
	std::cout << "password       : ";
	std::cin >> password_;

	UserLogin(login_, password_);

	std::cout << "to chat whit all users enter     (all) " << std::endl;
	std::cout << "to chat whit specific user enter (name) " << std::endl;
	std::cout << "enter Your choise here : ";
	std::cin >> user_;

	while (chatOn)
	{
		std::cout << "text    : ";
		std::cin >> message_;

		if (user_ == "all") // checks if message is addressed to all
		{
			for (auto i = 0; i < v_users_.size(); ++i)
			{
				found = true;
				std::cout << v_users_[i].getUserName() << std::endl; // couts all names of registerd users
			}
			std::cout << "\n";
		}
		else
		{
			for (auto i = 0; i < v_users_.size(); ++i) // 
			{
				if (user_ == v_users_[i].getUserName())
				{
					found = true;
					std::cout << "send to : " << v_users_[i].getUserName() << std::endl; // couts name of specific user
					break;
				}
			}
			if (!found)
			{
				throw "ERROR: user name is not matching current data of registred users!";
			}
		}

		chatOn = ChatOnSwitch(); // just a check if user wants to continue chat or not

		if (!chatOn) // logs out and finisches chat cycle, returns to main()
		{
			UserLogout(login_, password_);
		}
	}
}
bool Chat::Switch()
{
	int check = 0;
	std::cout << "continue chat (1) quit chat (0) : "; // simple continue question fo user, used in sendingMessages method
	std::cin >> check;

	if (check == 1)
	{
		return true;
	}
	else if (check == 0)
	{
		return false;
	}
	else
	{
		Switch();
	}
}
bool Chat::ChatOnSwitch()
{
	int check = 0; 
	std::cout << "logout (0) continue (1) : "; // same as continue question, but whit log out message insted. used in startChat method
	std::cin >> check;

	if (check == 1)
	{
		return true;
	}
	else if (check == 0)
	{
		return false;
	}
	else
	{
		ChatOnSwitch();
	}
}
void Chat::Menu() // menu info
{
	std::cout << "\n";
	std::cout << "to Register     (1)" << std::endl;
	std::cout << "to send Message (2)" << std::endl;
	std::cout << "to start Chat   (3)" << std::endl;
	std::cout << "to check info   (4)" << std::endl;
	std::cout << "to quit         (0)" << std::endl;
	std::cout << "\n";
}
