#ifndef ITEM_H
#define ITEM_H

#include <string>
    using std::string;

class Item
{
private:
    unsigned int inventoryCode;
    string description;
    float price;
    bool isItemWeighted;
public:
    Item(unsigned int inventoryCode,string description, float price, bool isItemWeighted);
    unsigned int getInventoryCode() const;
    string getDescription() const;
    float getPrice() const;
    bool isWeighted() const;
    virtual float getTotalPrice() const;
    // virtual string toString() final;
    virtual string itemStringRepresentation() const;
};
#endif