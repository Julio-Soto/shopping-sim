#include <vector>
    using std::vector;
#include <string>
    using std::string;
#include "Item.h"

class Customer;

class Item;

class Store
{
private:
    vector<Item*> stockList;
    Customer* customerCheckingOut;

public:
    Store();
    void stock(string fileName);
    void setCustomerCheckingOut(Customer* aCustomer);
    Item* getItem(unsigned int itemCode);
    vector<Item*> getStockList();
    // string checkOut();
};