#include <iostream>
    using std::endl;
    using std::cerr;
    using std::cout;
    using std::stoi;
    using std::stof;
#include <fstream>
    using std::ifstream;
    using std::getline;
#include <sstream>
    using std::istringstream;
#include <string>
    using std::string;
#include <iomanip>
#include "Store.h"

Store::Store(){}

void Store::greeting()
{
    cout << endl << endl << "          WELCOME TO STOP N SHOP" << endl;
    cout <<                 "        Hometown Grocer. We All Win" << endl <<endl;
    cout <<                 "15968 east Riviera Ave" << endl;
    cout <<                 "(555) 720-0420" <<endl << endl;
    cout <<                 "Your Cashier was: Roberto Soto" << endl;
    cout <<                 "--------------------------------------" << endl ;
}

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

void Store::checkOut(Customer* aCust)
{
    float price{0.0};
    float total{0.0};
    float tax{0.0};

    greeting();    
    for (size_t i{0}; i < aCust->getCart().size(); i++)
    {
        price = aCust->getCart()[i]->getTotalPrice();
        total += price;
    }
    if (total < 50)
    {
        for(size_t i{0}; i < aCust->getCart().size(); i++)
            cout << aCust->getCart()[i]->itemStringRepresentation();

        tax = total * 0.048; //sales tax

        cout << std::right << std::setw(33) << "TAX     $" << tax << endl;
        cout << std::right << std::setw(33) << "TOTAL   $" << (tax + total) << endl;
    }
    else
    {
        cout << "Your Total is: $" << total << endl;
        cout << "you only have $50 bucks" << endl;
        cerr << "CARD DECLINED!!" << endl << endl;
    }
}
