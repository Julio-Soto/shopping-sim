#include <array>
    using std::array;

#include <vector>
    using std::vector;

#include <string>
    using std::string;

#include "Store.h"


class Item;

class Customer
{
private:
    int amountOfItems;
    vector<Item*> cart;
    Store* currentStore;

public:
    Customer(int amountOfItems,Store* aStore);
    ~Customer();
    int getAmountOfItems() const;
    void setAmountofItems(unsigned int amount);
    vector<Item*> getCart() const;
    void fillCart();
};