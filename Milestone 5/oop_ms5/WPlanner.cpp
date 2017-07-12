//MILESTONE-5 
// FILE: WPlanner.cpp
// Version: 1.0
// Date: 12/08/2016
// Author: Saif Husain Khan
// Description:milestone
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<iostream>
#include <iomanip>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

using namespace std;
namespace ict {
	WPlanner::WPlanner(const char* filename) {
		strncpy(filename_, filename, 256);
		noOfItems_ = 0;
		loadRecs();
	}
	void WPlanner::saveRecs() {
		int i;
		fstream datafile_(filename_, ios::out);
		if (datafile_.is_open()){
			for (i = 0; i < noOfItems_; i++){
				items_[i]->store(datafile_);
			}
		}
		datafile_.close();
	}
	void WPlanner::loadRecs() {
		int readIndex = 0;
		char id;
		fstream datafile_(filename_, ios::in);
		if (datafile_.fail()){
			datafile_.clear();
			datafile_.close();
			fstream datafile_(filename_, ios::out);
			datafile_.close();
		}
		else{
			while (readIndex < MAX_NO_RECS && !datafile_.fail()){
				id = datafile_.get();
				if (id == 'C'){
					items_[readIndex] = new CustomMade;
				}
				else if (id == 'O'){
					items_[readIndex] = new OnShelf;
				}

				if (id == 'O' || id == 'C'){
					datafile_.ignore();

					items_[readIndex]->load(datafile_);
					readIndex++;
					datafile_.ignore(1000, '\n');
				}
			}
			noOfItems_ = readIndex;
			datafile_.close();
		}
	}
	int WPlanner::SearchItems(const char* sku) const {
		int i;
		int index = -1;
		for (i = 0; i < noOfItems_; i++){
			if (!strcmp(items_[i]->sku(), sku)){
				index = i;
			}
		}
		return index;
	}
	void WPlanner::getSku(char* sku) {
		cin.clear();
		cout << "Please enter the SKU: ";
		cin.ignore(0);
		cin.get();
		cin.getline(sku, MAX_SKU_LEN + 1);
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
	}
	void WPlanner::deleteItem() {
		std::cout << "Not implemented!" << endl << endl;
		}
	   void WPlanner::updateQty() {
			char* sku = new char[MAX_SKU_LEN+1];
			getSku(sku);
			int _id = -1;
				_id=SearchItems(sku);
			int tempItem;
			if (_id == -1) {
				cout << "Not found!" << endl << endl;
			}
			else {
				int x = 0;
				items_[_id]->display(cout,false);
				cout<<endl <<endl<< "Please enter the number of purchased goods: ";
				cin >> tempItem;
				if (cin.fail()) {
					cout << "Invalid Quantity value!" << endl;
				}
				else {
					x = (items_[_id]->qtyNeeded() - items_[_id]->quantity());
					if (tempItem <= x) {
						*items_[_id] += tempItem;
					}
					else {
						cout<< endl;
						cout << "Too many purchased, only " << items_[_id]->qtyNeeded() <<
							" needed, please return the extra " << -tempItem+items_[_id]->qtyNeeded() << "." << endl;
					}
					saveRecs();
					cout <<endl <<"Updated!\n"<<endl;
					
				}
			}
			
		}
		void WPlanner::listItems()const {
			int count = 0;
			double total = 0;
			cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
				<< "-----|-----|--------------------|-------|---|----|----|----------" << endl; 
			for (int i = 0; i < noOfItems_; i++) {
				cout << setfill(' ') << right << setw(4) << (i + 1) << " | " << *items_[i] << endl;
				count++;
				total += *items_[i];
			}
			cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl;
			cout << "Total cost of the Wedding: $" << fixed << setprecision(2) << showpoint << total << endl;
		        cout<<endl;
		}
		void WPlanner::addItem(bool isCustomMade) {
			Good *good;
			if (isCustomMade) {
				good = new CustomMade();
				cin >> *good;
				if (!cin.fail()) {
					items_[noOfItems_++] = good;
					saveRecs();
					cout <<endl <<"Good added\n"<<endl ;
				}
				else{
					cout << *good; 
					cin.clear();
					cin.ignore();
				}
			}
			else {
				good = new OnShelf();
				cin >> *good;
				if (!cin.fail()) {
					items_[noOfItems_++] = good;
					saveRecs();
					cout<<endl << "Good added\n" << endl;
				}
				else {
					cout << *good; 
					cin.clear();
					cin.ignore();
				}
			}
		}
		int WPlanner::menu() {
			int selection = -1;
			cout
				<< "Wedding Planner Management Program" << endl
				<< "1 - List goods" << endl
				<< "2 - Add On Shelf Good" << endl
				<< "3 - Add Custom-Made Good" << endl
				<< "4 - Update Good quantity" << endl
				<< "5 - Delete" << endl
				<< "0 - Exit program" << endl
				<< "> ";
			cin >> selection;
			cout << endl;
			if (cin.fail() || selection >5 || selection<0) {
				cin.clear();
				cin.ignore();
				selection = -1;
			}
			return selection;
		}
		int WPlanner::run() {
			int i;
			bool done = false;
			while (!done) {
				i=menu();		
				switch (i) {
				case 1:
					listItems();
					break;
				case 2:
					addItem(false);
					break;
				case 3:
					addItem(true);
					break;
				case 4:
					updateQty();
					break;
				case 5:
					deleteItem();
					break;
				case 0:
					done = true;
					cout << "Goodbye!!" << endl << endl;
					break;
				case -1:
					cout << "==Invalid Selection, try again.===";
					cout << endl << endl;
					break;
				}
			}
			return 0;
		} // WPlanner::run() end
	}


	/* outputs

	Wedding Planner Management Program
	1 - List goods
	2 - Add On Shelf Good
	3 - Add Custom-Made Good
	4 - Update Good quantity
	5 - Delete
	0 - Exit program
	>



	Not found!

	Please enter the number of purchased goods:

	Too many purchased, only 5 needed, please return the extra 15.

	Updated!

	Not implemented!

	*/
