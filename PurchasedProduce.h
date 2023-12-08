#ifndef PURCHASED_PRODUCE_H
#define PURCHASED_PRODUCE_H
#include "Item.h"
#include <string>
    using std::string;
#include <iostream>
    using std::cout;
    using std::endl;


class PurchasedProduce : public Item
{
private:
    float itemWeightInPounds;

public:
    PurchasedProduce(unsigned int inventoryCode, string description, float price, bool isItemWeighted, float itemWeightinPounds);
    float getItemWeight();
    float getTotalPrice() const override;
    string itemStringRepresentation() const;
};
#endif