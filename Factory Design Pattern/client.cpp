#include <iostream>
#include "ToyFactory.cpp"

using namespace std;

int main(int argc, char const *argv[])
{

    while (1)
    {
        int toyType;
        cout << "\n1. Create a Car \n2. Create a Bike \n3. Create a Plane \n4. EXIT" << endl;
        cout << "Enter a choice : ";
        cin >> toyType;

        if (toyType == 4)
        {
            break;
        }

        Toy *t = ToyFactory::createToy(toyType);

        if (t)
        {
            t->showProduct();
            delete t;
        }
    }

    cout << "Exited!" << endl;

    return 0;
}
