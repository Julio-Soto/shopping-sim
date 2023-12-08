//#include "shopMenu.h"
#include "Item.h"
#include "Customer.h"
#include <iostream>
    using std::cout;
    using std::endl;
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


int main()
{
    // shopMenu();
    Store myStore{};
    Store* myStorePtr = &myStore;
    myStore.stock("inventory-test.txt");
    int numOfitems = 5;
    Customer cust(numOfitems,&myStore);

    cust.fillCart();

    Item* itmPtr = myStore.getItem(2505);
    if(itmPtr != nullptr)
        cout << itmPtr->getDescription();
    else
        cout << "does not exist" << endl;

    /*
    cout << myStore.getStockList().size() << endl;
    for (size_t i{0}; i < myStore.getStockList().size(); i++)
    {

        cout << myStore.getStockList()[i]->getInventoryCode() << endl;
        cout << myStore.getStockList()[i]->getDescription() << endl;
        cout << myStore.getStockList()[i]->getPrice() << endl;
        cout << myStore.getStockList()[i]->getItemWeightedBool() << endl;
    }
    */
}