#include "PurchasedGenericItem.h"
#include <iomanip>
#include <sstream>
    using std::ostringstream;

PurchasedGenericItem::PurchasedGenericItem(unsigned int inventoryCode, string description, float price, bool isItemWeighted)
: Item(inventoryCode, description, price, isItemWeighted){}

string PurchasedGenericItem::itemStringRepresentation() const
{
    ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << getInventoryCode() << "    " << std::left << std::setw(25) << getDescription() << "$"<< getPrice() << endl << endl;
    return output.str();
}