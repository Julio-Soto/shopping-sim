#include "shopMenu.h"
#include <string>
#include <iostream>
    using std::cout;
    using std::endl;
    using std::cin;
#include <iomanip>
    using std::setw;
    using std::setfill;

void shopMenu(Store* myStore)
{

    
    bool leave = false;
    int shoppersChoice = 0;
    cout << setfill('~') << setw(40) << "~\n"
        << setfill(' ') << setw(32) << "Welcome to Stop N Shop!\n"
        << setfill('~') << setw(41) << "~\n\n"
        << "1) Shop\n" << "99) exit\n\n"
        << setfill('~') << setw(40) << "~\n";
    
    cin >> shoppersChoice;

    Customer newCustomer{0,myStore};
    Customer* newCustomerPtr = &newCustomer;


    while (leave == false)
    {
    
        if (shoppersChoice == 1)
        {
            cin.ignore();
            char shopAgain = ' ';
            int itemAmount;
            cout << "How many items would you like to purchase? (between 5-10)";
            cin >> itemAmount;
            newCustomerPtr->setAmountofItems(itemAmount);
            newCustomerPtr->fillCart();
            cout << setfill('~') << setw(40) << "~\n\n" << endl;
            myStore->checkOut(newCustomerPtr);
            cout << setfill('~') << setw(40) << "~\n\n" <<  endl;

            cout << "would you like to shop again? (Y) or (N): " << endl;
            cin >> shopAgain;

            if ((shopAgain == 'Y') || (shopAgain == 'y'))
            {
                shoppersChoice = 1;
            }
            else if ((shopAgain == 'N') || (shopAgain =='n'))
            {
                shoppersChoice = 99;
            }
            

        }
        
        else if (shoppersChoice == 99)
        {
            char leaveChoice = ' ';
            cout << "are you sure you wish to leave? (Y) or (N): ";
            cin >> leaveChoice;
            if ((leaveChoice == 'Y') || (leaveChoice == 'y'))
            {
                cout << "Goodbye! Thank you for shopping at Stop N Shop!\n";
                leave = true;
            }
            else if ((leaveChoice == 'N') || (leaveChoice =='n'))
            {
                leave = false;
            }
        }
    }

}