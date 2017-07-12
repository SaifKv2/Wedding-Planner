#ifndef ICT_ERROR_H__
#define ICT_ERROR_H__
#include <iostream>
namespace ict{
	class Error{
	private:
		char* message_;
	public:
		Error();
		Error(const char* Error);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		Error& operator=(const char* errorMessage);
		virtual ~Error();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
	};
	// operator<< overload prototype
	std::ostream&  operator<<(std::ostream& ostr, const Error& E);
}
#endif