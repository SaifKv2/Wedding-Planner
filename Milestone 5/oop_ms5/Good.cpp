#include <iostream>
#include <cstring>
#include "Good.h"
using namespace std;
namespace ict
{
	Good::Good()
	{
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		taxed_ = false;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}
	Good::Good(const char* sk, const char* na, double pri, int qtNeeded, bool tax)
	{
		sku(sk);
		name(na);
		price(pri);
		qtyNeeded(qtNeeded);
		taxed(tax);
		quantity(0);
	}
	Good::Good(const Good& A)
	{
		sku(A.sku_);
		name(A.name_);
		price(A.price_);
		qtyNeeded(A.qtyNeeded_);
		taxed(A.taxed_);
		quantity(A.quantity_);
	}
	Good& Good::operator=(const Good& A)
	{
		if (this != &A) {
			sku(A.sku_);
			name(A.name_);
			price(A.price_);
			qtyNeeded(A.qtyNeeded_);
			taxed(A.taxed_);
			quantity(A.quantity_);
		}
		return *this;
	}
	Good::~Good()
	{
		delete[] name_;
		name_ = nullptr;
	}
	void Good::sku(const char* sku) {
		strcpy(sku_, sku);
	}
	void Good::name(const char* name) {
		name_ = new char[strlen(name) + 1];
		if (name_ != nullptr){
			strncpy(name_, name, strlen(name) + 1);
		}
	}
	void Good::price(double price) {
		price_ = price;
	}
	void Good::qtyNeeded(int qtyNeeded) {
		qtyNeeded_ = qtyNeeded;
	}
	void Good::taxed(bool taxed) {
		taxed_ = taxed;
	}
	void Good::quantity(int quantity) {
		quantity_ = quantity;
	}
	const char* Good::sku() const {
		return sku_;
	}
	char* Good::name() const {
		return name_;
	}
	const double Good::price() const {
		return price_;
	}
	const int Good::qtyNeeded() const {
		return qtyNeeded_;
	}
	const bool Good::taxed() const {
		return taxed_;
	}
	const int Good::quantity() const {
		return quantity_;
	}
	const double Good::cost() const {
		if (!taxed_)
			return price_;
		else
			return (price_ + (price_ * TAX));
	}
	bool Good::operator==(const char* sku) {
		if (strcmp(sku_, sku) == 0)
			return true;
		else
			return false;
	}
	int Good:: operator+=(int qty) {
		return quantity_ += qty;
	}
	double operator +=(double& A, const Good& B)
	{
		A += B.cost() * B.quantity();
		return A;
	}
	std::ostream& operator<<(std::ostream& os, const Good& B){
		return B.display(os, true);
	}
	std::istream& operator>>(std::istream& is, Good& B){
		return B.conInput(is);
	}
}
