#ifndef ICT_DATE_H__
#define ICT_DATE_H__
// header file includes
#include <iostream>

namespace ict {
   // Error code values go here
	#define NO_ERROR 0 
	#define CIN_FAILED 1 
	#define YEAR_ERROR 2
	#define MON_ERROR 3
	#define DAY_ERROR 4

   class Date {
   private:
      // private member variables
	   int year_;
	   int mon_;
	   int day_;
	   int readErrorCode_;
      // private member functions and setters

	   void errCode(int errorCode);
       int value()const;

   public:
      // constructors
	   Date();
	   Date(int year, int mon, int day);

      // operator overloads
	   bool operator==(const Date& D)const;
	   bool operator!=(const Date& D)const;
	   bool operator<(const Date& D)const;
	   bool operator>(const Date& D)const;
	   bool operator<=(const Date& D)const;
	   bool operator>=(const Date& D)const;


      // IO member functions
	   std::istream& read(std::istream& is = std::cin);
	   std::ostream& write(std::ostream& os = std::cout) const;

      // public member functions and getters
      int mdays()const;
	  int errCode() const;
	  bool bad() const;

   };
   // operator << and >> overloads prototypes for ostream and istream go here
   std::istream& operator>> (std::istream& is, Date& D);
   std::ostream& operator<<(std::ostream& os, const Date& D);

}
#endif
