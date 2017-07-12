#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict{
	class Good : public ReadWritable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Good();
		Good(const char* sk, const char* na, double pri, int qtNeeded, bool tax = true); 
		Good& operator =(const Good&);
		Good(const Good&);
		virtual ~Good();
		void sku(const char* sk);
		void name(const char* nm);
		void price(double cst);
		void taxed(bool tx);
		void quantity(int qty);
		void qtyNeeded(int qtyNeeded);
		const char* sku() const;
		char* name() const;
		const double price() const;
		const bool taxed() const;
		const int quantity() const;
		const int qtyNeeded()const;
		const double cost() const;
		bool operator==(const char* right);
		int operator+=(int right);


	};
	double operator+=(double& A, const Good& B);
	std::ostream& operator<<(std::ostream& os, const Good& B);
	std::istream& operator>>(std::istream& is, Good& B);
}


#endif