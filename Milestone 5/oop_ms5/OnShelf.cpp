#include <iostream>
#include <fstream>
#include<sstream>
#include <iomanip>
#include <cstring>
#include "OnShelf.h"
#include"CustomMade.h"
using namespace std;
namespace ict{
	//Constructor
	OnShelf::OnShelf(char filetag_)
	{
		recTag_ = filetag_;
	}
	std::fstream& OnShelf::store(std::fstream& file, bool addNewLine)const{
		file << recTag_ << "," << sku() << "," << name() << "," << price() << ","
			<< taxed() << "," << quantity() << "," << qtyNeeded();
		if (addNewLine){
			file << endl;
		}
		return file;
	}
	std::fstream& OnShelf::load(std::fstream& file){
		char tempSku[MAX_SKU_LEN + 1];
		char tempName[1000];
		bool tempTaxed;
		double tempPrice;
		int tempQuantity;
		int tempQtyNeeded;
		file.getline(tempSku, MAX_SKU_LEN + 1, ',');
		sku(tempSku);
		file.getline(tempName, 1000, ',');
		name(tempName);
		file >> tempPrice;
		price(tempPrice);
		file.ignore();
		file >> tempTaxed;
		taxed(bool(tempTaxed));
		file.ignore();
		file >> tempQuantity;
		quantity(tempQuantity);
		file.ignore();
		file >> tempQtyNeeded;
		qtyNeeded(tempQtyNeeded);
		return file;
	}
	std::ostream& OnShelf::display(std::ostream& os, bool linear)const{
		if (err_.isClear()){
			char tempName[21];
			strncpy(tempName, name(), 20);
			tempName[20] = '\0';
			char tax;
			if (linear){
				if (taxed() == true){
					tax = 't';
				}
				else
					tax = ' ';
				os << sku() << " |";
				os << setw(19);
				os << left << name();
				os << right << " |";
				os << setw(7) << setprecision(2) << fixed << cost() << "| " << tax << " | ";
				os.setf(ios::right);
				os << setw(3) << quantity() << "| ";
				os << setw(3) << qtyNeeded() << "|";
			}
			else{
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << fixed << setprecision(2) << price() << endl
					<< "Price after tax: ";
				if (taxed()){
					os << fixed << setprecision(2) << cost();
				}
				else{
					os << "N/A";
				}
				os << endl << "Quantity On Hand: " << quantity() << endl
					<< "Quantity Needed: " << qtyNeeded();
			}
		}
		else{
			os << err_;
		}
		return os;
	}
	std::istream& OnShelf::conInput(std::istream& istr){
		char s[100];
		char n[1000];
		double p;
		char t;
		int q;
		int qn;
		if (istr.fail() == false) {
			err_.clear();
			cout << "Sku: ";
			istr >> s;
			if (istr.fail() == false) {
				sku(s);
			}
			cout << "Name: ";
			istr >> n;
			if (istr.fail() == false) {
				name(n);
			}
			cout << "Price: ";
			istr >> p;
			if (istr.fail()) {
				err_.message("Invalid Price Entry");
			}
			else {
				price(p);
			}
			if (err_.isClear()) {
				cout << "Taxed: ";
				istr >> t;
				if (t == 'Y' || t == 'y') {
					taxed(true);
				}
				else if (t == 'N' || t == 'n') {
					taxed(false);
				}
				else {
					err_.message("Only (Y)es or (N)o are acceptable");
					istr.setstate(std::ios::failbit);
				}
			}
			if (err_.isClear()) {
				cout << "Quantity On hand: ";
				istr >> q;
				if (istr.fail()) {
					err_.message("Invalid Quantity Entry");
				}
				else {
					quantity(q);
				}
			}
			if (err_.isClear()) {
				cout << "Quantity Needed: ";
				istr >> qn;
				if (istr.fail()) {
					err_.message("Invalid Quantity Needed Entry");
				}
				else {
					qtyNeeded(qn);
				}
			}
		}
		return istr;
	}
}
