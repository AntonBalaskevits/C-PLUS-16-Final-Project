#pragma once
#include <string>
#include <vector>

class Message
{
	std::string message_;
	std::string from_;
	std::string to_;
public:
	Message() = default;
	Message(const std::string& message, const std::string& from, const std::string& to);
	Message(const Message& other);
	Message& operator = (Message& other);
	Message(Message&& other) noexcept;
	Message& operator = (Message&& other) noexcept;
	~Message();

	const std::string getMessage() const;
	const std::string getFrom() const;
	const std::string getTo() const;

	void setMessage(const std::string& message);
	void setFrom(const std::string& from);
	void setTo(const std::string& to);
};
