#include <iostream>
#include <string>
#include <vector>
#include "classes.h"

using namespace std;

void displayMenu();
void addProductToInventory(inventory& Products);
void updateProductQuantity(inventory& Products);
void searchForProduct(const inventory& Products);

int main()
{
    inventory Products;

    int choice;
    do
    {
        displayMenu();
        cin >> choice;

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
    cout << "1. Add a Product\n";
    cout << "2. Display Products in Inventory\n";
    cout << "3. Update Quantity of a Product\n";
    cout << "4. Search for a Product\n";
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
    cout << "6. Bakery" << endl;
    cout << "7. Frozen Foods" << endl;
    cout << "8. Canned Foods" << endl;
    cout << "9. Snacks" << endl;
    cout << "10. Beverages" << endl;
    cout << "11. citrusfruit" << endl;
    cout << "12. orange" << endl;

    

    int category;
    cout << "Enter the product category (1-10): ";
    cin >> category;
    cin.ignore();
    string citrus_type;
    string orange_type;
    if(category == 11 || category == 12)
    {
        if (category == 11)
        {
            cout << "Enter the citrustype of the fruit: ";
            getline(cin, citrus_type);
        }
        else
        {
            cout << "Enter the citrus type of the fruit: ";
            getline(cin, citrus_type);
            cout << "Enter the orange type of the citrusfruit: ";
            getline(cin, orange_type);
        }
    }


    string name;
    double price;
    int quantity;

    cout << "Enter the name of the product: " << endl;
    getline(cin, name);

    cout << "Enter the quantity of the product: ";
    cin >> quantity;

    cout << "Enter the price of the product: ";
    cin >> price;

    string typeOrOrigin;

    // Create a product based on the selected category and add it to the inventory
    switch (category)
    {
    case 1:
        cout << "Enter the origin of the fruit: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new fruit(name, price, quantity, typeOrOrigin));
        break;
    case 2:
        cout << "Enter the type of the vegetable: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new vegetable(name, price, quantity, typeOrOrigin));
        break;
    case 3:
        cout << "Enter the origin of the dairy product: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new dairy(name, price, quantity, typeOrOrigin));
        break;
    case 4:
        cout << "Enter the type of meat: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new meats(name, price, quantity, typeOrOrigin));
        break;
    case 5:
        cout << "Enter the type of seafood: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new seafood(name, price, quantity, typeOrOrigin));
        break;
    case 6:
        cout << "Enter the type of bakery item: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new bakery(name, price, quantity, typeOrOrigin));
        break;
    case 7:
        cout << "Enter the type of frozen food: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new frozenFoods(name, price, quantity, typeOrOrigin));
        break;
    case 8:
        cout << "Enter the type of canned food: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new cannedFoods(name, price, quantity, typeOrOrigin));
        break;
    case 9:
        cout << "Enter the type of snack: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new snacks(name, price, quantity, typeOrOrigin));
        break;
    case 10:
        cout << "Enter the type of beverage: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new beverages(name, price, quantity, typeOrOrigin));
        break;
    case 11:
        cout << "Enter the origin of fruit: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new citrusfruit(name,price,quantity,typeOrOrigin,citrus_type));
        break;
    case 12:
        cout << "Enter the origin of fruit: ";
        cin.ignore();
        getline(cin, typeOrOrigin);
        Products.add_inventory(new orange(name,price,quantity,typeOrOrigin,citrus_type,orange_type));
        break;
        
    default:
        cout << "\nInvalid category choice." << endl;
        break;
    }
}

void updateProductQuantity(inventory& Products)
{
    cout << "\nEnter the name of the product to update quantity: ";
    cin.ignore();
    string productName;
    getline(cin, productName);

    cout << "Enter the new quantity: ";
    int newQuantity;
    cin >> newQuantity;

    Products.update_quantity(productName, newQuantity);
}

void searchForProduct(const inventory& Products)
{
    cout << "\nEnter the name of the product to search: ";
    cin.ignore();
    string productName;
    getline(cin, productName);

    const product* foundProduct = Products.search_product(productName);
    if (foundProduct != nullptr)
    {
        cout << "\nProduct found in the inventory: " << endl;
        foundProduct->display();
    }
    else
    {
        cout << "Product not found in the inventory." << endl;
    }
}
//check