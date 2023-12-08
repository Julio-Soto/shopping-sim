#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <array>
    using std::array;

#include <vector>
    using std::vector;

#include <string>
    using std::string;

#include "Item.h"

class Store; //forward declaration
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
    unsigned int generateRandomCode() const;
    float generateRandomWeight();
    void setAmountofItems(unsigned int amount);
    vector<Item*> getCart() const;
    void fillCart();
};

#endif