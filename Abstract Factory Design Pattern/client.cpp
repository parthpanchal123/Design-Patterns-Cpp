
#include <iostream>
#include "CarFactory.cpp"
using namespace std;

int main()
{

    int car_type;
    while (1)
    {

        CarFactory *factory;
        cout << "1. LuxuryCar \n2. Simple Car \n3. Exit" << endl;
        cin >> car_type;

        if (car_type == 3)
        {
            break;
        }

        switch (car_type)
        {
        case 1:
            factory = new LuxuryCarFactory;
            break;
        case 2:
            factory = new SimpleCarFactory;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        Car *car = factory->buildWholeCar();
        car->printDetails();
        delete car;
    }

    cout << "Exited" << endl;

    return 0;
}