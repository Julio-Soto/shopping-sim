#include "Item.h"
#include <sstream>
    using std::ostringstream;
#include <iostream>
    using std::cout;
    using std::endl;


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
float Item::getTotalPrice() const
{
    return price;//price per unit
}
bool Item::isWeighted() const
{
    return isItemWeighted;
}
string Item::itemStringRepresentation() const
{
   ostringstream output;
    output << "This is an Inventory Item";
    return output.str();
}