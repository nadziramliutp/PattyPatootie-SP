#include <iostream>
#include <iomanip>
#include <cctype> 
using namespace std;

void displayWelcomeMessage() {
    // Display welcome message
    cout << "-----------------------------------------------------------------------------\n";
    cout << "                           Welcome to Patty Patootie Burger \n";
    cout << "-----------------------------------------------------------------------------\n";
}

void displayMenu() {
    // Display menu
    cout << "\n                                     Menu \n";
    cout << "+---------------------------------------------------------------------------+\n";
    cout << "| Item                                    | Price (Set) | Price (Ala Carte) |\n";
    cout << "+---------------------------------------------------------------------------+\n";
    cout << "| A - Beef Burger Set                     | RM 13.00    | RM 7.00           |\n";
    cout << "| B - Double Beef Burger Set              | RM 15.00    | RM 10.00          |\n";
    cout << "| C - Fillet O Fish Burger Set            | RM 14.00    | RM 9.00           |\n";
    cout << "| D - Chicken Burger Set                  | RM 12.50    | RM 6.00           |\n";
    cout << "| E - Vege Burger Set                     | RM 10.00    | RM 5.00           |\n";
    cout << "| F - Mushroom Burger Set                 | RM 13.00    | RM 7.00           |\n";
    cout << "| G - Breakfast Burger Set with Egg Burger| RM 7.50     | RM 3.50           |\n";
    cout << "+---------------------------------------------------------------------------+\n";
    cout << "                                    Extra Items:\n";
    cout << "                  +-----------------------------------------+\n";
    cout << "                  | Item                      | Price       |\n";
    cout << "                  +-----------------------------------------+\n";
    cout << "                  | N - Nuggets (6 pcs)       | RM 8.00     |\n";
    cout << "                  | W - Wedges                | RM 7.00     |\n";
    cout << "                  | I - Ice Cream             | RM 3.00     |\n";
    cout << "                  +-----------------------------------------+\n";
    cout << endl;
}


void displayDateTime() {
    
    // Display current date and time in Malaysia time (UTC+8)
    time_t now = time(0);
    tm *ltm = gmtime(&now);  // Use gmtime to get the time in UTC
    ltm->tm_hour += 8;       // Convert to Malaysia time (UTC+8)

    // Correct for any overflow in the hour field
    if (ltm->tm_hour >= 24) {
        ltm->tm_hour -= 24;
        ltm->tm_mday += 1;
    }

    cout << "Date and Time: ";
    cout << 1900 + ltm->tm_year << "-";
    cout << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-";
    cout << setw(2) << setfill('0') << ltm->tm_mday << " ";
    cout << setw(2) << setfill('0') << ltm->tm_hour << ":";
    cout << setw(2) << setfill('0') << ltm->tm_min << ":";
    cout << setw(2) << setfill('0') << ltm->tm_sec << endl;
}

// Structure for order details
struct {
    char type;
    double price;
    bool repeat; //check either the entered input is valid or not to be proceed
} order;

// Structure for menu details
struct {
    char initial, type;
    int frequency;
    bool repeat;
    string name;
} menu;

int main() {
    
    // Save menu prices, 1st column = set, 2nd column = ala carte
    double burgerprice[7][2] = {
        {13, 7},   // Beef burger A
        {15, 10},  // Double beef B
        {14, 9},   // Fillet O Fish C
        {12.5, 6}, // Chicken burger D
        {10, 5},   // Vege burger E
        {13, 7},   // Mushroom burger F
        {7.5, 3.5} // Breakfast set G
    };


    int x, y;
    displayWelcomeMessage();
    displayMenu();
    
    
    do {        //Do-while loop use to ask at least once, if false then loop again. 
    
        // Prompt for dine-in or takeaway
        cout << "Dine in (D/d) or Takeaway(T/t) ? :";
        cin >> order.type;
        
        //Determine the type of order, and save the price to count in final for receipt 
        if (toupper(order.type) == 'D') {
            order.price = 0;                    //If order is dine-in, the price is RM 0 
            break; 
        } else if (toupper(order.type) == 'T') {
            order.price = 1.50;                 // If order is take away, the price RM 1.50
            break;
        } else {
            cout << "Please choose either dine-in or takeaway" << endl;
            order.repeat = true;                //if user enter invalid input, ask again
        }
        
        
        
    } while (order.repeat == true);

    // Prompt for number of menu items to order
    cout << "How many menu you would like to order ? ";
    cin >> menu.frequency;
    
    // declaring array to store ordered menu name, 
    string menureceipt[menu.frequency];
    double menupricereceipt[menu.frequency];

    // loop to ask user to enter menu they would like to order
    for (int i = 1; i <= menu.frequency; i++) {
        cout << "\n";
        cout << "Which sets you would like to order? : ";
        cin >> menu.initial;

        // Determine which burger is ordered
        switch (toupper(menu.initial)) {
            case 'A':
                x = 0;
                menu.name = "Beef Burger     ";
                break;
            case 'B':
                x = 1;
                menu.name = "Double Burger   ";
                break;
            case 'C':
                x = 2;
                menu.name = "Fillet O Fish   ";
                break;
            case 'D':
                x = 3;
                menu.name = "Chicken Burger  ";
                break;
            case 'E':
                x = 4;
                menu.name = "Vege Burger     ";
                break;
            case 'F':
                x = 5;
                menu.name = "Mushroom Burger ";
                break;
            case 'G':
                x = 6;
                menu.name = "Breakfast Burger";
                break;
        }

        do {
            // Prompt for set or ala carte
            cout << "Set(S/s) or A lar carte(A/a) ? : ";
            cin >> menu.type;
            if (toupper(menu.type) == 'S') {
                y = 0;
                break;
            } else if (toupper(menu.type) == 'A') {
                y = 1;
                break;
            } else {
                cout << "Please Enter S/s or A/a !!!" << endl;
                menu.repeat = true;
            }
        } while (menu.repeat == true);

        int qtymenu;
        // Prompt for quantity
        cout << "Enter the quantity : ";
        cin >> qtymenu;

        menureceipt[i - 1] = menu.name;
        menupricereceipt[i - 1] = qtymenu * burgerprice[x][y];
    }

    int extrafrequency;

    // Prompt for number of extra items
    cout << "\nHow many extra items you would like to order ? ";
    cin >> extrafrequency;

    string extrareceipt[extrafrequency + 1];
    double extrapricereceipt[extrafrequency + 1], extraqty;
    double extraprice[3] = {8.00, 7.00, 3.00};
    if (extrafrequency > 0) {
        for (int z = 1; z <= extrafrequency; z++) {
            cout << "\n";
            cout << "Which items you would like to order? : ";
            cin >> menu.initial;
            switch (toupper(menu.initial)) {
                case 'N':
                    menu.name = "Nuggets ( 6pcs )";
                    x = 0;
                    break;
                case 'W':
                    menu.name = "Wedges          ";
                    x = 1;
                    break;
                case 'I':
                    menu.name = "Ice Cream       ";
                    x = 2;
                    break;
            }
            cout << "Enter the Quantity : ";
            cin >> extraqty;
            extrareceipt[z - 1] = menu.name;
            extrapricereceipt[z - 1] = extraprice[x] * extraqty;
        }
    }

    // Calculate the total price
    double sum=0;
    for (int j=0;j<menu.frequency;j++) {
        sum += menupricereceipt[j];
    }
    for (int j=0;j<menu.frequency;j++) {
        sum += extrapricereceipt[j];
    }


    // Display the receipt
    cout << "\n                                    RECEIPT :\n";
    cout << "                        ";
    displayDateTime();

    cout << "                  +-----------------------------------------+\n";
    for (int n = 0; n < menu.frequency; n++) {
        cout << "                  |" << menureceipt[n] << "            |" << fixed << setprecision(2) << menupricereceipt[n] << endl;
    }

    cout << "                  +-----------------------------------------+\n";
    for (int m = 0; m < extrafrequency; m++) {
        cout << "                  |" << extrareceipt[m] << "            |" << fixed << setprecision(2) << extrapricereceipt[m] << endl;
    }
    cout << "                  +-----------------------------------------+\n";
    if (order.type == 'T' || order.type == 't') {
        cout << "                  |" << "Takeaway charge " << "            |" << order.price << "\n";
        sum += order.price;
    }

    cout << "                  |Total:          " << "            |" << sum << "\n";
}
