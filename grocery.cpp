#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "classes.h"

using namespace std;

void displayMenu();
void addProductToInventory(inventory& Products);
void addMangoToInventory(inventory& Products);
void updateProductQuantity(inventory& Products);
void searchForProduct(const inventory& Products);
void removeProductFromInventory(inventory& Products);

int main()
{
    inventory Products;

    int choice;
    do
    {
        displayMenu();
        try {
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Invalid input. Please enter a number."; // exception handling for invalid input
            }
        }
        catch (const char* msg) {
            cerr << msg << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addProductToInventory(Products);
            break;
        case 2:
            Products.display_info();
            break;
        case 3:
            updateProductQuantity(Products);
            break;
        case 4:
            searchForProduct(Products);
            break;
        case 5:
            removeProductFromInventory(Products);
            break;
        case 0:
            cout << "\n>>> Exiting the program...\n\n";
            break;
        default:
            cout << "\n!!! Invalid choice. Please try again.\n\n";
            break;
        }

    } while (choice != 0);

    return 0;
}

void displayMenu()
{
    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\n\tGrocery Store Inventory Management System\n\n";
    cout << "1. Add a new product to the inventory." << endl;
    cout << "2. Display all products in the inventory." << endl;
    cout << "3. Update the quantity of an existing product." << endl;
    cout << "4. Search for a specific product in the inventory." << endl;
    cout << "5. Remove a product from the inventory." << endl;
    cout << "0. Exit\n";
    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "Enter your choice: ";
}

void addProductToInventory(inventory& Products)
{
    cout << "\nProduct Category" << endl;
    cout << "1. Fruit" << endl;
    cout << "2. Vegetable" << endl;
    cout << "3. Dairy" << endl;
    cout << "4. Meats" << endl;
    cout << "5. Seafood" << endl;
    cout << "6. Baked Good" << endl;
    cout << "7. Frozen Foods" << endl;
    cout << "8. Canned Foods" << endl;
    cout << "9. Snacks" << endl;
    cout << "10. Beverages" << endl;

    int category;
    cout << "Enter the product category (1-10): ";
    cin >> category;
    cin.ignore();

    if (category == 1) {
        cout << "Would you like to add a Mango product specifically?\n1. Yes\n2. No\n";
        int isMango;
        cin >> isMango;
        cin.ignore();
        if (isMango == 1) {
            addMangoToInventory(Products);
            return;
        }
    }

    string name;
    double price;
    int quantity;
    string typeOrOrigin;

    switch (category)
    {
    case 1:
        cout << "Enter the name of fruit: ";
        break;
    case 2:
        cout << "Enter the name of vegetable: ";
        break;
    case 3:
        cout << "Enter the name of dairy product: ";
        break;
    case 4:
        cout << "Enter the name of meat: ";
        break;
    case 5:
        cout << "Enter the name of seafood: ";
        break;
    case 6:
        cout << "Enter the name of baked good: ";
        break;
    case 7:
        cout << "Enter the name of frozen food: ";
        break;
    case 8:
        cout << "Enter the name of canned food: ";
        break;
    case 9:
        cout << "Enter the name of snack: ";
        break;
    case 10:
        cout << "Enter the name beverage: ";
        break;
    default:
        cout << "Enter the name of the product: ";
        break;
    }
    getline(cin, name);

    cout << "Enter the quantity of the product: ";
    cin >> quantity;
    cin.ignore();

    // validate if the entered quantity is non-negative
    if (quantity < 0) {
        throw "Invalid quantity. Quantity cannot be negative.";
    }

    cout << "Enter the price of the product: ";
    cin >> price;
    cin.ignore();

    // validate if the entered price is non-negative
    if (price < 0) {
        throw "Invalid price. Price cannot be negative.";
    }

    if (category == 1) {
        cout << "Enter the origin of the fruit: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 2) {
        cout << "Enter the type of vegetable: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 3) {
        cout << "Enter the type of dairy: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 4) {
        cout << "Enter the type of meat: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 5) {
        cout << "Enter the type of seafood: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 6) {
        cout << "Enter the type of baked good: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 7) {
        cout << "Enter the type of frozen food: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 8) {
        cout << "Enter the type of canned food: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 9) {
        cout << "Enter the type of snacks: ";
        getline(cin, typeOrOrigin);
    }
    if (category == 10) {
        cout << "Enter the type of beverage: ";
        getline(cin, typeOrOrigin);
    }

    switch (category)
    {
    case 1:
        Products.add_inventory(new fruit(name, price, quantity, typeOrOrigin));
        break;
    case 2:
        Products.add_inventory(new vegetable(name, price, quantity, typeOrOrigin));
        break;
    case 3:
        Products.add_inventory(new dairy(name, price, quantity, typeOrOrigin));
        break;
    case 4:
        Products.add_inventory(new meats(name, price, quantity, typeOrOrigin));
        break;
    case 5:
        Products.add_inventory(new seafood(name, price, quantity, typeOrOrigin));
        break;
    case 6:
        Products.add_inventory(new bakedGood(name, price, quantity, typeOrOrigin));
        break;
    case 7:
        Products.add_inventory(new frozenFoods(name, price, quantity, typeOrOrigin));
        break;
    case 8:
        Products.add_inventory(new cannedFoods(name, price, quantity, typeOrOrigin));
        break;
    case 9:
        Products.add_inventory(new snacks(name, price, quantity, typeOrOrigin));
        break;
    case 10:
        Products.add_inventory(new beverages(name, price, quantity, typeOrOrigin));
        break;
    }
}

void addMangoToInventory(inventory& Products) {
    string name, variety, region, taste;
    double price;
    int quantity;
    //cin.ignore();
    cout << "Enter the mango name: ";
    getline(cin, name);
    cout << "Enter the mango variety: ";
    getline(cin, variety);
    cout << "Enter the mango region: ";
    getline(cin, region);
    cout << "Enter the mango taste: ";
    getline(cin, taste);
    cout << "Enter the price: ";
    cin >> price;
    cin.ignore();

    // validate if the entered price is non-negative
    if (price < 0) {
        throw "Invalid price. Price cannot be negative.";
    }

    cout << "Enter the quantity: ";
    cin >> quantity;
    cin.ignore();

    // validate if the entered quantity is non-negative
    if (quantity < 0) {
        throw "Invalid quantity. Quantity cannot be negative.";
    }

    Chaunsa* mango = new Chaunsa(name, price, quantity, variety, region, taste);
    Products.add_inventory(mango);
    cout << "\n-= Mango product added successfully. =-" << endl;
}

void updateProductQuantity(inventory& Products)
{
    cout << "\nEnter the name of the product to update quantity: ";
    string productName;
    getline(cin, productName);

    cout << "Enter the new quantity: ";
    int newQuantity;
    cin >> newQuantity;
    cin.ignore();

    // validate if the entered quantity is non-negative
    if (newQuantity < 0) {
        throw "Invalid quantity. Quantity cannot be negative.";
    }

    Products.update_quantity(productName, newQuantity);
}

void searchForProduct(const inventory& Products)
{
    cout << "\nEnter the name of the product to search: ";
    string productName;
    getline(cin, productName);

    const product* foundProduct = Products.search_product(productName);
    if (foundProduct != nullptr) {
        cout << "\n-= Product found =-" << endl;
        cout << "------------------------" << endl;
        foundProduct->display();
    }
    else {
        cout << "\n-= Product not found in inventory. =-" << endl;
    }
}

void removeProductFromInventory(inventory& Products)
{
    cout << "\nEnter the name of the product to remove: ";
    string productName;
    getline(cin, productName);

    Products.remove_product(productName);
}

