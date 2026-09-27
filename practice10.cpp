#include <iostream>
using namespace std;

int square(int number)
{
return number * number;
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << square(number) << endl;

    return 0;

}