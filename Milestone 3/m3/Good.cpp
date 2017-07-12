#include <cstring>
#include <iostream>
#include "wpgeneral.h"
#include "Good.h"
using namespace std;
namespace ict {

	Good::Good()
	{
		sku_[0] = 0;
		name_ = nullptr;
		price_ = 0;
		taxed_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Good::Good(const char* sku, char* name, double price, int qtyNeeded, bool taxed)
	{
		
		strncpy(sku_, sku, MAX_SKU_LEN + 1);
		name_ = new char[strlen(name) + 1];
		quantity_ = 0;
		strcpy(name_, name);
		price_ = price;
		qtyNeeded_ = qtyNeeded;
	}
	Good::Good(const char * sku2, const char * name2)
	{
		strncpy(sku_, sku2, MAX_SKU_LEN + 1);
		name_ = new char[strlen(name2) + 1];
		strcpy(name_, name2);
		price_ = 0;
		taxed_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Good& Good::operator=(const Good& E)
	{
		delete[] name_;
		
		strncpy(sku_, E.sku_, MAX_SKU_LEN +1);
		name_ = new char[strlen(E.name_) + 1];
		strcpy(name_, E.name_);
		taxed_ = E.taxed_;
		price_ = E.price_;
		quantity_ = E.quantity_;
		qtyNeeded_ = E.qtyNeeded_;
		// TODO: insert return statement here
		return *this;
	}

	Good::Good(const Good & E)
	{
		strncpy(sku_, E.sku_, MAX_SKU_LEN + 1);
		name_ = new char[strlen(E.name_) + 1];
		strcpy(name_, E.name_);
		price_ = E.price_;
		taxed_ = E.taxed_;
		quantity_ = E.quantity_;
		qtyNeeded_ = E.qtyNeeded_;
	}

	Good::~Good()
	{
		delete[] name_;
		
		name_ = nullptr;
	}

	void Good::sku(const char * sku)
	{
		strncpy(sku_, sku, MAX_SKU_LEN + 1);
	}

	void Good::name(const char * name)
	{
		strcpy(name_, name);
	}

	void Good::price(double price)
	{
		price_ = price;
	}

	void Good::quantity(int quantity)
	{
		quantity_ = quantity;
	}

	void Good::qtyNeeded(int qtyNeeded)
	{
		qtyNeeded_ = qtyNeeded;
	}

	void Good::taxed(int taxed)
	{
		taxed_ = taxed;
	}


	const char * Good::sku() const
	{
		return sku_;
	}

	double Good::price() const
	{
		return price_;
	}

	const char * Good::name() const
	{
		return name_;
	}

	bool Good::taxed() const
	{
		return taxed_;
	}

	int Good::quantity() const
	{
		return quantity_;
	}

	int Good::qtyNeeded() const
	{
		return qtyNeeded_;
	}

	double Good::cost() const
	{
		double ret;
		if (taxed_ == 0)
			ret = price_;
		else
			ret = price_ + (price_ * TAX);

		return ret;
	}

	bool Good::operator==(const char * A)
	{
		return !strcmp(sku_, A);
	}

	int Good::operator+=(int quantity)
	{
		return quantity_ += quantity;
	}

	int Good::operator-=(int quantity)
	{
		return quantity_ -= quantity;
	}


	double& operator+=(double& ref, const Good& E)
	{
		return ref = ref + (E.cost() * E.quantity());
	}
	bool Good::isTrue() const {
		return sku_[0] == 0 && name_ == nullptr 
			&& price_ == 0 && taxed_ == 0
			&& quantity_ == 0 && qtyNeeded_ == 0;
	}
	std::ostream& operator<<(std::ostream& os, const Good& E)
	{
		return E.display(os, E.isTrue());
	}

	std::istream& operator >> (std::istream& is, Good& E)
	{
		return E.conInput(is);
	}

}