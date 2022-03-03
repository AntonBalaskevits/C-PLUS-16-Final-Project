#include "message.h"

Message::Message(const std::string& message, const std::string& from, const std::string& to)
	: message_(message), from_(from), to_(to) {}

Message::Message(const Message& other)
{
	message_ = other.message_;
	from_ = other.from_;
	to_ = other.to_;
}
Message& Message::operator = (Message& other)
{
	message_ = other.message_;
	from_ = other.from_;
	to_ = other.to_;
	return *this;
}
Message::Message(Message&& other) noexcept
{
	message_ = other.message_;
	from_ = other.from_;
	to_ = other.to_;
	other.message_.erase();
	other.from_.erase();
	other.to_.erase();
}
Message& Message::operator = (Message&& other) noexcept
{
	message_ = other.message_;
	from_ = other.from_;
	to_ = other.to_;
	other.message_.erase();
	other.from_.erase();
	other.to_.erase();
	return *this;
}
Message::~Message() {}

const std::string Message::getMessage() const
{
	return message_;
}
const std::string Message::getFrom() const
{
	return from_;
}
const std::string Message::getTo() const
{
	return to_;
}

void Message::setMessage(const std::string& message)
{
	message_.erase();
	message_ = message;
}
void Message::setFrom(const std::string& from)
{
	from_.erase();
	from_ = from;
}
void Message::setTo(const std::string& to)
{
	to_.erase();
	to_ = to;
}