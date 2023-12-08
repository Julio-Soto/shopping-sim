#ifndef PURCHASED_GENERIC_ITEM_H
#define PURCHASED_GENERIC_ITEM_H
#include "Item.h"
#include <string>
    using std::string;
#include <iostream>
    using std::cout;
    using std::endl;


class PurchasedGenericItem : public Item
{
private:

public:
    PurchasedGenericItem(unsigned int inventoryCode, string description, float price, bool isItemWeighted);
    string itemStringRepresentation() const;
};
#endif