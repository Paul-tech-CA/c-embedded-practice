#include <iostream>
using namespace std;

int multiplyByTwo(int number)
{
    return number * 2;
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << multiplyByTwo(number) << endl;

    return 0;
}