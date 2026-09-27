#include <iostream>

bool isTemperatureSafe(int temperature){
    if(temperature >= 10 && temperature <= 70)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool canSystemRun(int temperature, bool emergencyStop){
    if(!emergencyStop && isTemperatureSafe(temperature))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printSystemStatus(bool canRun){
    if(canRun)
    {
        std::cout << "SYSTEM RUNNING\n";
    }
    else 
    {
        std::cout << "SYSTEM STOPPED\n";
    }
}

int main(){
    int temperature;
    std::cout << "Enter temperature: ";
    std::cin >> temperature;

    bool emergencyStop;
    std::cout << "Emergency stop 0 or 1: ";
    std::cin >> emergencyStop;

    bool canRun = canSystemRun(temperature, emergencyStop);
    printSystemStatus(canRun);
    return 0;
}