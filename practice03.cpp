#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int count = 0;

    for (int i = 1; i <= 40; i++)
    {
        if (i % 3 == 0 || i % 7 == 0)
        {
            sum += i;
            count ++;
        }
        
    }
    cout << "Sum: " << sum << endl;
    cout << "Count: " << count << endl;
    return 0;

}