#pragma once

#include <iostream>
#include <vector>
#include <string>

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
        cout << "Origin: " << origin << endl;
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
class citrusfruit: public fruit{
    protected:
    string citrustype;

    public:
    citrusfruit(const string& a1, double a2, int a3, const string& a4, const string& a5)
    :     fruit(a1,a2,a3,a4), citrustype(a5){}
    
    virtual void display() const override
    {
        fruit::display();
        cout << "type: " << citrustype << endl;
    }
};

class orange: public citrusfruit{
    protected:
    string orangetype;

    public:
    orange(const string& a1, double a2, int a3, const string& a4, const string& a5,const string& a6)
    : citrusfruit(a1,a2,a3,a4,a5), orangetype(a6){}

    virtual void display() const override
    {
        citrusfruit::display();
        cout << "type_of: " << orangetype << endl;
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

class bakery : public product
{
protected:
    string type;

public:
    bakery(const string& a1, double a2, int a3, const string& a4)
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

class inventory
{
private:
    vector<product*> products;

public:
    ~inventory()
    {
        // Free the memory allocated to product objects
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
        for (product* p : products)
        {
            if (p->get_name() == productName)
            {
                p->set_quantity(newQuantity);
                cout << "Quantity updated successfully." << endl;
                return;
            }
        }

        cout << "Product not found in the inventory." << endl;
    }

    const product* search_product(const string& productName) const
    {
        for (const product* p : products)
        {
            if (p->get_name() == productName)
            {
                return p;
            }
        }

        return nullptr;
    }

    void display_info() const
    {
        if (products.empty())
        {
            cout << "Inventory is empty." << endl;
        }
        else
        {
            cout << "\nProducts in Inventory:" << endl;
            for (const product* p : products)
            {
                p->display();
                cout << "------------------------" << endl;
            }
        }
    }
};
