#ifndef __ict_WPlanner_H__
#define __ict_WPlanner_H__
#include "wpgeneral.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"
namespace ict {
	class WPlanner {
		char filename_[256];
		Good* items_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfItems_;
		int menu();
		void loadRecs();
		void saveRecs();
		void listItems()const;
		int SearchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isCustomMade);
		void deleteItem();
		void getSku(char* sku);
	public:
		//Copy and assignment prevention goes here:
		WPlanner(const char* filename);
		int run();
	};
}
#endif

