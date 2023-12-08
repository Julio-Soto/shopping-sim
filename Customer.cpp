#include <iostream>
    using std::cout;
    using std::endl;
#include <random>
#include "Customer.h"

Customer::Customer(int amountOfItems,Store* Store)
: amountOfItems(amountOfItems), currentStore(Store){}
Customer::~Customer()
{
    // will delete the new items that we created
}
int Customer::getAmountOfItems() const
{
    return amountOfItems;
}
vector<Item*> Customer::getCart() const
{
    return cart;
}

void Customer::setAmountofItems(unsigned int amount)
{
    amountOfItems = amount;
}
void Customer::fillCart()
{
    Item* selectedItem{nullptr};
    int randomItemCode{0};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(2300, 2399);

    while(cart.size() < amountOfItems)
    {
        selectedItem = currentStore->getItem((distribution(gen)));
        if(selectedItem != nullptr)
            cart.push_back(selectedItem);
    }
    cout << cart.size() << endl;
    /*
    for (size_t i{0}; i < currentStore->getStockList().size(); i++)
    {

        cout << currentStore->getStockList()[i]->getInventoryCode() << endl;
        cout << currentStore->getStockList()[i]->getDescription() << endl;
        cout << currentStore->getStockList()[i]->getPrice() << endl;
        cout << currentStore->getStockList()[i]->getItemWeightedBool() << endl;
    }*/
}