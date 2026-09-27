#include <iostream>
using namespace std;

int main()
{
int fizzCount = 0;
int buzzCount = 0;
int fizzBuzzCount = 0;
int normalCount = 0;

    for (int i = 1; i <= 20; i++)
{
    
    if (i % 3 == 0 && i % 5 == 0)    
    {
        cout << i << " FizzBuzz" << endl;
        fizzBuzzCount++;
    }
    else if (i % 3 == 0)
    {
        cout << i << " Fizz" << endl;
        fizzCount++;
    }
    else if (i % 5 == 0)
    {
        cout << i << " Buzz" << endl;
        buzzCount++;
    }
    else
    {
        cout << i << endl;
        normalCount++;
    }
    
    
}

cout << "Fizz: " << fizzCount << endl;
cout << "Buzz: " << buzzCount << endl;
cout << "FizzBuzz: " << fizzBuzzCount << endl;
cout << "Normal: " << normalCount << endl;
cout << "Total: " << fizzCount + buzzCount + fizzBuzzCount + normalCount << endl;

return 0;
    
}