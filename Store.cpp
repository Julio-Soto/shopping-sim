#include <iostream>
    using std::endl;
    using std::cerr;
    using std::stoi;
    using std::stof;
#include <fstream>
    using std::ifstream;
    using std::getline;
#include <sstream>
    using std::istringstream;
#include <string>
    using std::string;
#include "Store.h"

Store::Store(){}

void Store::stock(string fileName)
{
    string itemString;
    unsigned int code;
    string description;
    float price;
    int slashDelimiterPos{0};
    bool isItemWeighted;
    int barDelimiterPos{0};
    
    ifstream inventoryFile(fileName);
    
    if (!inventoryFile.is_open()) 
    {
        cerr << "We will be closed for remodeling" << endl;
    }

    while (getline(inventoryFile, itemString))
    {
        istringstream inputItemLine(itemString);

        barDelimiterPos = itemString.find("|");
        code = stoi(itemString.substr(0,barDelimiterPos));
        itemString.erase(0, barDelimiterPos + 2);

        barDelimiterPos = itemString.find("|");
        description = itemString.substr(0,barDelimiterPos);
        itemString.erase(0, barDelimiterPos + 1);

        slashDelimiterPos = itemString.find("/");

        if(slashDelimiterPos == -1)
        {
            price = stof(itemString.substr(0));
            itemString.erase(itemString.length());
            isItemWeighted = false;
        }
        else
        {
            price = stof(itemString.substr(0, slashDelimiterPos));
            itemString.erase(itemString.length());
            isItemWeighted = true;
        }

        Item* itemPtr = new Item{code, description, price, isItemWeighted};
        stockList.push_back(itemPtr);

    }

    inventoryFile.close();
}

void Store::setCustomerCheckingOut(Customer* aCustomer)
{
    customerCheckingOut = aCustomer;
}

Item* Store::getItem(unsigned int itemCode)
{
    for(int i=0; i < stockList.size();++i)
    {
        if(stockList[i]->getInventoryCode() == itemCode)
            return stockList[i];
    }
    return nullptr;
}
vector<Item*> Store::getStockList()
{
    return stockList;
}
