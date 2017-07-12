#include "Error.h"
#include <cstring>
namespace ict{

	Error::Error() //Sets the message date memeber to empty state
	{
		message_ = nullptr;
	}

	Error::Error(const char * Error) //Sets the message to null and updates it to Error
	{
		message_ = nullptr;
		message(Error);
	}

	Error & Error::operator=(const char * errorMessage) //sets the message to Error and return the correct object
	{
		message(errorMessage);
		delete[] message_;
		message_ = new char[strlen(errorMessage) + 1];
		strncpy(message_, errorMessage, (strlen(errorMessage) + 1));
		// TODO: insert return statement here
		return *this;
	}

	Error::~Error() //destructor: deallocactes the memory
	{
		delete[] message_;
	}

	void Error::clear() //deallocates the memory and sets it to empty string
	{
		delete[] message_;
		message_ = nullptr;
	}

	bool Error::isClear() const //returns true if message is an empty string
	{
		return message_ == 0;
	}

	void Error::message(const char * value) //Sets the message of the Error object to a new value
	{
		delete[] message_;
		message_ = new char[strlen(value) + 1];
		strncpy(message_, value, (strlen(value) + 1));
	}

	const char * Error::message() const //return the err message
	{
		return message_;
	}
	
	std::ostream& operator<<(std::ostream& os, const Error& errmsg)
	{
		if (errmsg.isClear())
		{
			os << "";
		}
		else
		{
			os << errmsg.message();
		}
		// TODO: insert return statement here
		return os;
	}
}