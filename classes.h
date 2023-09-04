#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class product
{
protected:
    string name;
    double price;
    int quantity;

public:
    product(const string& a1, double a2, int a3 = 0)
        : name(a1), price(a2), quantity(a3)
    {
    }

    void set_name(const string& a1) { name = a1; }
    void set_price(double a2) { price = a2; }
    void set_quantity(int a3) { quantity = a3; }

    string get_name() const { return name; }
    double get_price() const { return price; }
    int get_quantity() const { return quantity; }

    virtual double calculate_price(int quantity) { return price * quantity; }

    virtual void display() const
    {
        cout << "Product Name: " << name << endl;
        cout << "Product Price: $" << price << endl;
        cout << "Product Quantity: " << quantity << endl;
    }
};

class fruit : public product
{
protected:
    string origin;

public:
    fruit(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), origin(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Origin: " << origin << endl;
    }
};

class Mangoes : public product {
protected:
    string variety;
public:
    Mangoes(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), variety(a4)
    {
    }

    virtual void display() const override {
        product::display();
        cout << "Mango Variety: " << variety << endl;
    }
};

class PakistaniMangoes : public Mangoes {
protected:
    string region;
public:
    PakistaniMangoes(const string& a1, double a2, int a3, const string& a4, const string& a5)
        : Mangoes(a1, a2, a3, a4), region(a5)
    {
    }

    virtual void display() const override {
        Mangoes::display();
        cout << "Region: " << region << endl;
    }
};

class Chaunsa : public PakistaniMangoes {
protected:
    string taste;
public:
    Chaunsa(const string& a1, double a2, int a3, const string& a4, const string& a5, const string& a6)
        : PakistaniMangoes(a1, a2, a3, a4, a5), taste(a6)
    {
    }

    virtual void display() const override {
        PakistaniMangoes::display();
        cout << "Taste: " << taste << endl;
    }
};


class vegetable : public product
{
protected:
    string type;

public:
    vegetable(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class dairy : public product
{
protected:
    string origin;

public:
    dairy(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), origin(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << origin << endl;
    }
};

class meats : public product
{
protected:
    string type;

public:
    meats(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class seafood : public product
{
protected:
    string type;

public:
    seafood(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class bakedGood : public product
{
protected:
    string type;

public:
    bakedGood(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class frozenFoods : public product
{
protected:
    string type;

public:
    frozenFoods(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class cannedFoods : public product
{
protected:
    string type;

public:
    cannedFoods(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class snacks : public product
{
protected:
    string type;

public:
    snacks(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

class beverages : public product
{
protected:
    string type;

public:
    beverages(const string& a1, double a2, int a3, const string& a4)
        : product(a1, a2, a3), type(a4)
    {
    }

    virtual void display() const override
    {
        product::display();
        cout << "Type: " << type << endl;
    }
};

// custom exception for negative price input
class NegativePriceException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Invalid price. Price cannot be negative.";
    }
};

// custom exception for negative quantity input
class NegativeQuantityException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Invalid quantity. Quantity cannot be negative.";
    }
};

class inventory
{
private:
    vector<product*> products;

public:
    ~inventory()
    {
        for (product* p : products)
        {
            delete p;
        }
    }

    void add_inventory(product* item)
    {
        products.push_back(item);
    }

    void update_quantity(const string& productName, int newQuantity)
    {
        // validate if the entered quantity is non-negative
        if (newQuantity < 0) {
            throw NegativeQuantityException();
        }

        string lowerProductName = productName;
        transform(lowerProductName.begin(), lowerProductName.end(), lowerProductName.begin(), ::tolower);

        for (product* p : products)
        {
            string lowerName = p->get_name();
            transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (lowerName == lowerProductName)
            {
                p->set_quantity(newQuantity);
                cout << "\n-= Quantity updated successfully! =-" << endl;
                return;
            }
        }

        cout << "\n-= Product not found in the inventory. =-" << endl;
    }

    const product* search_product(const string& productName) const
    {
        string lowerProductName = productName;
        transform(lowerProductName.begin(), lowerProductName.end(), lowerProductName.begin(), ::tolower);

        for (const product* p : products)
        {
            string lowerName = p->get_name();
            transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (lowerName == lowerProductName)
            {
                return p;
            }
        }

        return nullptr;
    }

    void remove_product(const string& productName)
    {
        string lowerProductName = productName;
        transform(lowerProductName.begin(), lowerProductName.end(), lowerProductName.begin(), ::tolower);

        for (auto it = products.begin(); it != products.end(); ++it)
        {
            string lowerName = (*it)->get_name();
            transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (lowerName == lowerProductName)
            {
                delete* it;
                products.erase(it);
                cout << "\n-= Product removed successfully! =-" << endl;
                return;
            }
        }

        cout << "\n-= Product not found in the inventory. =-" << endl;
    }

    void display_info() const
    {
        if (products.empty())
        {
            cout << "\n-= Inventory is empty. =-" << endl;
        }
        else
        {
            cout << "\n-= Products in Inventory =-" << endl;
            cout << "------------------------" << endl;
            for (const product* p : products)
            {
                p->display();
                cout << "------------------------" << endl;
            }
        }
    }
};

