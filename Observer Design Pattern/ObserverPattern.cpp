#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Car
{
    int _position;
    vector<class Observer *> _observerList;

public:
    int getPosition()
    {
        return _position;
    }

    void setPosition(int newPosition)
    {
        _position = newPosition;
        notify();
    }

    void attach(Observer *obs)
    {
        _observerList.push_back(obs);
    }

    void detach(Observer *obs)
    {
        _observerList.erase(remove(_observerList.begin(), _observerList.end(), obs), _observerList.end());
    }

    void notify();
};

class Observer
{
    Car *_car;

public:
    Observer(Car *car) : _car(car)
    {
        _car->attach(this);
    }

    virtual void update() = 0;

protected:
    Car *getCar()
    {
        return _car;
    }
};

void Car::notify()
{
    for (int i = 0; i < _observerList.size(); ++i)
    {
        _observerList[i]->update();
    }
}

class LeftObserver : public Observer
{
public:
    LeftObserver(Car *car) : Observer(car) {}
    void update()
    {
        int pos = getCar()->getPosition();
        if (pos < 0)
        {
            cout << "Left side" << endl;
        }
    }
};

class RightObserver : public Observer
{
public:
    RightObserver(Car *car) : Observer(car) {}
    void update()
    {
        int pos = getCar()->getPosition();
        if (pos > 0)
        {
            cout << "Right side" << endl;
        }
    }
};

class MiddleObserver : public Observer
{
public:
    MiddleObserver(Car *car) : Observer(car) {}
    void update()
    {
        int pos = getCar()->getPosition();
        if (pos == 0)
        {
            cout << "Middle " << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Car *car = new Car();

    LeftObserver leftObserver(car);
    RightObserver rightObserver(car);
    MiddleObserver middleObserver(car);

    cout << "Hit left right button to drive a car in your city!!! and press break to close" << endl;

    char pressedButton;
    bool breakLoop = false;

    while (breakLoop == false)
    {
        cin >> pressedButton;

        switch (pressedButton)
        {
        case 108:
        { // l -->  press for left side
            car->setPosition(-1);
            break;
        }
        case 99:
        { // c --> press for center
            car->setPosition(0);
            break;
        }
        case 114:
        { // r --> press for right side
            car->setPosition(1);
            break;
        }
        case 98:
        { // b --> press for break
            breakLoop = true;
            break;
        }
        default:
        {
            cout << "Please drive responsibly!!" << endl;
            break;
        }
        }
    }
    cout << "Byee..." << endl;

    delete car;
    return 0;
}
