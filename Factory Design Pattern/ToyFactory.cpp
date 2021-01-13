#include <iostream>
#include "ToyObjects.cpp"

using namespace std;

enum Toys
{
    CAR = 1,
    BIKE,
    PLANE
};
class ToyFactory
{
public:
    static Toy *createToy(int toyType)
    {
        Toy *toy = NULL;

        switch (toyType)
        {
        case Toys::CAR:
            toy = new Car;
            break;
        case Toys::BIKE:
            toy = new Bike;
            break;
        case Toys::PLANE:
            toy = new Plane;
            break;

        default:
            cout << "Invalid toy type" << endl;
            return NULL;
            break;
        }

        toy->prepareParts();
        toy->assembleParts();
        toy->applyLabel();

        return toy;
    }
};