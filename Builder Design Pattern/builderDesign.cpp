#include <iostream>

using namespace std;

class Car
{
    string _car;
    string _body;
    string _engine;

public:
    Car(string carType) : _car(carType)
    {
    }
    void setEngine(string type) { _engine = type; }
    void setBody(string body) { _body = body; }
    string getEngine() { return _engine; }
    string getBody() { return _body; }

    void show()
    {
        cout << "Car Type: " << _car << endl
             << "Body Type: " << _body << endl
             << "Engine Type: " << _engine << endl
             << endl;
    }
};

class CarBuilder
{
protected:
    Car *_car;

public:
    virtual void getParts() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    Car *getCar()
    {
        return _car;
    }
};

class MarutiBuilder : public CarBuilder
{
public:
    void getParts() { _car = new Car("Maruti Car"); }
    void buildEngine() { _car->setEngine("Maruti Car Engine"); }
    void buildBody() { _car->setBody("Maruti Car Body"); }
};

class FerrariBuilder : public CarBuilder
{
public:
    void getParts() { _car = new Car("Ferrari Car"); }
    void buildEngine() { _car->setEngine("Ferrari Car Engine"); }
    void buildBody() { _car->setBody("Ferrari Car Body"); }
};

class Director
{
    CarBuilder *builder;

public:
    Car *createCar(CarBuilder *builder)
    {
        builder->getParts();
        builder->buildBody();
        builder->buildEngine();
        return builder->getCar();
    }
};

int main(int argc, char const *argv[])
{

    Director dir;
    MarutiBuilder mb;
    FerrariBuilder fb;

    Car *ferrari = dir.createCar(&fb);
    Car *maruti = dir.createCar(&mb);

    ferrari->show();
    maruti->show();

    delete ferrari;
    delete maruti;

    return 0;
}
