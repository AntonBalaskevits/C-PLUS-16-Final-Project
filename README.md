# C-PLUS-16-Final-Project
## Final Project on C++ basic constructions
### student developer Anton Balaskevits
### Solution
- I decided to execute as indicated in the conditions. First, registration must be completed, and then you can use the password and login to use the chat or send messages to a specific user. At least two users must be registered, if this condition is not met then an exception is thrown. I also tried to provide an exception in cases where an incorrect password or login was entered, and a registration check in the case when user whit the same login is already registered.
### Classes description
- The User class contains fields for the string type for the login, password, and name, a constructor that accepts a login, password, and username, a destructor, and getters-setters.
- The Message class contains fields of type string for the message, fields for the name to whom the message was sent and fields for the name from whom the message was sent, the constructor that takes in messages, to and from whom, also tried to use the rule of five for movement semantics. And of course getters and setters.
- The Chat class contains fields of type vector for user registrations and vector for logins, as well as field for a smart pointer of type unique_ptr and fields for (logins, passwords, to whom, from whom, for name, messages) that are needed for console input. Default constructor, and destructor.
#### Classes used : User, Message , and Chat
#### Description of Chat class methods
- first methot is RegisterNewUser() creates new object of type User whit login,password and name. After that is done, object is placed in vector container, using vector method push_back(newUser).
- UserLogin() method that is used in Chat() method for logins. Takes in login and password. Works pretty much the same as RegisterNewUser() method but uses different vector container dedicated for logins.
- UserLogout() used in conjunction whit UserLogin() method. if User wants to quit chat or enter chat whit diffirent login it automatically logges out current user using vector erase() method.
- ChatInfo() simply outputs current number of registered, users that are currently logged in and their names.
- sendingMessages() method that contains whole cycle of sending and reciving messages that are send to a specific user or all users. Takes as input login, password, message and name to who is message for. After that using smart pointer (unique_ptr) creates object new_message_ptr. When all checks are done, using std::move() method places new_message_ptr in new smart pointer container that can be read by providing on console input user login and password.
- startChat() method works almost the same as sendingMessages() method but whit shorter cycle. All it does, takes in login and password and message. Then sends to a specific user or all users whit out asking them to enter their password and login.
- Switch() and ChatOnSwitch() are used just for asking user if he/she wishes to continue or not in chat cycle.
- Menu() is self explanatory, just couts to console all available choices of program.
