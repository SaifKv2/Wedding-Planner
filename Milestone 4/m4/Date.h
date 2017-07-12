

#ifndef ICT_DATE_H__
#define ICT_DATE_H__
#include <iostream>
namespace ict{
#define NO_ERROR   0  
#define CIN_FAILED 1  
#define YEAR_ERROR 2
#define MON_ERROR  3  
#define DAY_ERROR  4  

	class Date{
	private:
		int value()const;
		void errCode(int errorCode);
	public:
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;
		Date();
		Date(int year, int mon, int day);
		int mdays()const;
		int errCode();
		bool bad()const;
		void validate();
		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};
	std::istream&  operator>>(std::istream& istr, Date& D);
	std::ostream&  operator<<(std::ostream& ostr, const Date& D);
}
#endif
