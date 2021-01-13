#include <iostream>

using namespace std;

class Toy
{
protected:
    string name;
    double price;

public:
    virtual void prepareParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;

    ~Toy()
    {
        cout << name << " object destroyed" << endl;
    }
};

class Car : public Toy
{
public:
    void prepareParts()
    {
        cout << "\nPreparing a Car" << endl;
    }
    void assembleParts()
    {
        cout << "Assembling a Car" << endl;
    }
    void applyLabel()
    {
        cout << "Applying a Car label" << endl;
        name = "Ferrari";
        price = 1234.00;
    }
    void showProduct()
    {
        cout << "Car Details : \n Car name : " << name << "Price : " << price << endl;
    }
};

class Bike : public Toy
{
public:
    void prepareParts()
    {
        cout << "Preparing a Bike" << endl;
    }
    void assembleParts()
    {
        cout << "Assembling a Bike" << endl;
    }
    void applyLabel()
    {
        cout << "Applying a Bike label" << endl;
        name = "Hayabusa";
        price = 1230.00;
    }
    void showProduct()
    {
        cout << "Bike Details : \n Bike name : " << name << "Price : " << price << endl;
    }
};
class Plane : public Toy
{
public:
    void prepareParts()
    {
        cout << "Preparing a Plane" << endl;
    }
    void assembleParts()
    {
        cout << "Assembling a Plane" << endl;
    }
    void applyLabel()
    {
        cout << "Applying a Plane label" << endl;
        name = "Airbus 360";
        price = 123456.00;
    }
    void showProduct()
    {
        cout << "Plane Details : \n Plane name : " << name << "Price : " << price << endl;
    }
};