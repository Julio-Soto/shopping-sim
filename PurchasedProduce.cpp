#include "PurchasedProduce.h"
#include <sstream>
    using std::ostringstream;
#include <iostream>
#include <iomanip>

#include <string>

PurchasedProduce::PurchasedProduce(unsigned int inventoryCode, string description, float price, bool isItemWeighted, float itemWeight)
: Item(inventoryCode, description, price, isItemWeighted), itemWeightInPounds{itemWeight}{}
float PurchasedProduce::getItemWeight()
{
    return itemWeightInPounds;
}
float PurchasedProduce::getTotalPrice() const
{
    return (itemWeightInPounds * getPrice());
} 
string PurchasedProduce::itemStringRepresentation() const
{
    ostringstream output;
    output << std::fixed << std::setprecision(2);
    output  << itemWeightInPounds << "lb" << "  @ $" << getPrice() << "/lb\n"
           << getInventoryCode() << "    " << std::left << std::setw(25) << getDescription() << "$"<< (itemWeightInPounds * getPrice()) << endl << endl;
    return output.str();
}