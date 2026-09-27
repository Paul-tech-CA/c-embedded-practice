#include <iostream>

 bool isTemperatureSafe(int temperature){
        if (temperature >= 10 && temperature <= 70)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    
    void printSystemStatus(bool safe){
        if(safe)
        {
            std::cout << "SYSTEM IS OK\n";
        }
        else 
        {
            std::cout << "ALARM\n";
        }
    }


int main()
{
    int temperature;

    std::cout << "Enter temperature: ";
    std::cin >> temperature;

    bool safe = isTemperatureSafe(temperature);

    printSystemStatus(safe);
    
    return 0;
}