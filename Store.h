#ifndef STORE_H
#define STORE_H

#include <vector>
    using std::vector;
#include <string>
    using std::string;
#include "Item.h"
#include "Customer.h"

class Store
{
private:
    vector<Item*> stockList;

public:
    Store();
    void greeting();
    void stock(string fileName);
    Item* getItem(unsigned int itemCode);
    vector<Item*> getStockList();
    void checkOut(Customer*);
};

#endif