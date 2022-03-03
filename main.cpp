#include <iostream>

#include "chat.h"
#include "message.h"
#include "user.h"

int main()
{
	Chat chat;

	bool on = true;
	int operation = 0;

	std::cout << "Welcome to chat 1.0!" << std::endl;

	while (on)
	{
		chat.Menu();

		std::cin >> operation;

		switch (operation)
		{
		case 1:
			chat.RegisterNewUser();
			break;
		case 2:
			try { chat.sendingMessages(); }
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;
		case 3:
			try { chat.startChat(); }
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;
		case 4:
			chat.ChatInfo();
			break;
		case 0:
			on = false;
			break;
		default:
			std::cout << "you made an illegal choice. Please try again." << std::endl;
			on = true;
			break;
		}
	}

	std::cout << "Thank you for using Chat 1.0, see u next time)" << std::endl; 

	return 0;
}

