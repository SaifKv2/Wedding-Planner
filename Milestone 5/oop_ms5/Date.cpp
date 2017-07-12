#include <iostream>
#include "Date.h"
#include "wpgeneral.h"
using namespace std;
namespace ict{

	// private member variables

	void Date::errCode(int errorCode){
		readErrorCode_ = errorCode;
	}
	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}
	void Date::validate() {
		if (!((year_ >= MIN_YEAR) && (year_ <= MAX_YEAR)))
		{
			readErrorCode_ = YEAR_ERROR;
		}
		else if (!((mon_ >= 1 && mon_ <= 12)))
		{
			readErrorCode_ = MON_ERROR;
		}
		else if (!((day_ >= 1 && day_ <= mdays())))
		{
			readErrorCode_ = DAY_ERROR;
		}
		else
			readErrorCode_ = NO_ERROR;
	}
	// public member functions and getters

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
	int Date::errCode()
	{
		return readErrorCode_;
	}
	bool  Date::bad()const
	{
		if (readErrorCode_ != NO_ERROR)
			return true;
		else
			return false;
	}
	// constructor
	Date::Date() {
		readErrorCode_ = NO_ERROR;
		day_ = 0;
		mon_ = 0;
		year_ = 0;
	}
	Date::Date(int year, int mon, int day){
		readErrorCode_ = NO_ERROR;
		year_ = year;
		mon_ = mon;
		day_ = day;
	}
	//IO member funcion
	std::istream& Date::read(std::istream& istr = std::cin)
	{
		istr >> year_;
		istr.ignore(1, '/');
		istr >> mon_;
		istr.ignore(1, '/');
		istr >> day_;
		if ((istr.fail()))
			readErrorCode_ = CIN_FAILED;
		else
			validate();
		return istr;
	}
	std::ostream& Date::write(std::ostream& ostr = std::cout)const
	{
		ostr << year_ << "/";
		if (mon_ < 10) {
			ostr << "0";
		}
		ostr << mon_ << "/";
		if (day_ < 10) {
			ostr << "0";
		}
		ostr << day_;
		return ostr;
	}
	// operator << and >> overloads
	std::ostream& operator<<(std::ostream& ostr, const Date& D)
	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Date& D)
	{
		return D.read(istr);
	}
	// operator overloads
	bool Date::operator==(const Date& D) const {
		return this->value() == D.value();
	}
	bool Date::operator!=(const Date& D)const
	{
		return this->value() != D.value();
	}
	bool Date::operator<(const Date& D)const
	{
		return this->value() < D.value();
	}
	bool Date::operator>(const Date& D)const
	{
		return this->value() > D.value();
	}
	bool Date::operator<=(const Date& D)const
	{
		return this->value() <= D.value();
	}
	bool Date::operator>=(const Date& D)const
	{
		return this->value() >= D.value();
	}
}