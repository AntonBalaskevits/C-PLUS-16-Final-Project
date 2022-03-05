# C-PLUS-16-Final-Project
## Final Project on C++ basic constructions
### student developer Anton Balaskevits
### Solution
- I decided to execute as indicated in the conditions. First, registration must be completed, and then you can use the password and login to use the chat or send messages to a specific user. At least two users must be registered, if this condition is not met then an exception is thrown. I also tried to provide an exception in cases where an incorrect password or login was entered, and a registration check in the case when user whit the same login is already registered.
### Classes description
- The User class contains fields for the string type for the login, password, and name, a constructor that accepts a login, password, and username, a destructor, and getters-setters.
- The Message class contains fields of type string for the message, fields for the name to whom the message was sent and fields for the name from whom the message was sent, the constructor that takes in messages, to and from whom, also tried to use the rule of five for movement semantics. And of course getters and setters.
- The Chat class contains fields of type vector for user registrations and vector for logins, as well as field for a smart pointer of type unique_ptr and fields for (logins, passwords, to whom, from whom, for name, messages) that are needed for console input. Default constructor, and destructor.
