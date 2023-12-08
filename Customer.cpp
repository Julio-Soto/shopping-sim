#include <iostream>
    using std::cout;
    using std::endl;
#include <random>
#include "Customer.h"
#include "Store.h"
#include "PurchasedGenericItem.h"
#include "PurchasedProduce.h"

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

unsigned int Customer::generateRandomCode() const
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(2300,2399);
    return distribution(gen);
}

float Customer::generateRandomWeight() 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(100, 300);

    float randomWeight = distribution(gen);
    return (randomWeight / 100); 
}

void Customer::fillCart()
{
    Item* selectedItem{nullptr};
    float weight{0};

    while(cart.size() < amountOfItems)
    {
        selectedItem = currentStore->getItem((generateRandomCode()));
        if(selectedItem != nullptr)
            if(selectedItem->isWeighted())
            {
                weight = generateRandomWeight();
                cart.push_back(new PurchasedProduce(selectedItem->getInventoryCode(),selectedItem->getDescription(),selectedItem->getPrice(),selectedItem->isWeighted(),weight));
            }
            else
                cart.push_back(new PurchasedGenericItem(selectedItem->getInventoryCode(),selectedItem->getDescription(),selectedItem->getPrice(),selectedItem->isWeighted()));
    }
}