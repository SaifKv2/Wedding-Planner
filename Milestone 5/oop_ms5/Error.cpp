#include "Error.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace ict{
	Error::Error(){
		message_ = nullptr;
	}
	Error::Error(const char* Error){
		message_ = nullptr;
		message(Error);
	}
	Error& Error:: operator=(const char* errorMessage){

		delete[]message_;
		message_ = new char[strlen(errorMessage) + 1];
		strcpy(message_, errorMessage);
		clear();
		message(errorMessage);
		return *this;
	}
	Error:: ~Error(){
		delete[]message_;
	}
	void Error::clear(){
		delete[]message_;
		message_ = nullptr;
	}

	bool Error::isClear()const{
		//bool ret = true;
		if (message_ == nullptr)
			return  true;
		else
			return false;

	}
	void Error::message(const char* value){
		delete[]message_;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}
	const char* Error::message()const{
		return message_;
	}
	std::ostream& operator<<(std::ostream& ostr, const Error& E){
		if (E.isClear())
			ostr << "";
		else
			ostr << E.message();
		return ostr;
	}
}
