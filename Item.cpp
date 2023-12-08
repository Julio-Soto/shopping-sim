#include "Item.h"

Item::Item(unsigned int inventoryCode,string description, float price, bool isItemWeighted)
: inventoryCode{inventoryCode}, description{description}, price{price}, isItemWeighted{isItemWeighted} {}
unsigned int Item::getInventoryCode() const
{
    return inventoryCode;
}
string Item::getDescription() const
{
    return description;
}
float Item::getPrice() const
{
    return price;
}
bool Item::getItemWeightedBool() const
{
    return isItemWeighted;
}