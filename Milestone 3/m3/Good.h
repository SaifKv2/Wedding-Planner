#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict{
  class Good: public ReadWritable {
	char sku_ [MAX_SKU_LEN + 1];
	char * name_;
	double price_;
	bool taxed_;
	int quantity_;
	int qtyNeeded_;
	
  public:
	  Good();
	  virtual ~Good();
	  Good(const char* sku, char * name, double price, int qtyNeeded, bool taxed = true);
	  Good(const char * sku2, const char * name2);
	  Good& operator=(const Good& E);
	  Good(const Good& E);
	  

	  
	  void sku(const char* sku);
	  void name(const char* name);
	  void price(double price);
	  void quantity(int quantity);
	  void qtyNeeded(int qtyNeeded);
	  void taxed(int taxed);

	  
	  const char* sku() const;
	  double price() const;
	  const char* name() const;
	  bool taxed() const;
	  int quantity() const;
	  int qtyNeeded() const;

	  double cost() const;


	  bool operator== (const char* A);
	  int operator+= (int quantity);
	  int operator-=(int quantity);

	  bool isTrue() const;
	};


  double& operator+=(double& num, const Good& E);
  std::ostream& operator<<(std::ostream& os, const Good& E);
  std::istream& operator >> (std::istream& is, Good& E);
}

#endif