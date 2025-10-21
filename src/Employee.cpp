#include "Employee.h"
#include <iostream>
#include <cmath>

Employee::Employee()
{
    setAge(35);
    setIsAlive(true);
    suspicion = 0.f;
    suspicionTimer = 0.f;
    heartsRemaining = 3;
}

void Employee::update(float deltaTime, PlayerThief &player)
{
    suspicionTimer += deltaTime;

    if (suspicionTimer >= 1.0f)
    {
        suspicion += suspicionRate;
        suspicionTimer = 0.f;
        std::cout << "Employee suspicion: " << suspicion << "\n";

        if (suspicion >= suspicionLimit)
        {
            suspicion = 0.f;
            heartsRemaining--;
            std::cout << "Heart lost! Remaining: " << heartsRemaining << "\n";

            if (heartsRemaining <= 0)
            {
                std::cout << "Caught by employee!\n";

                player.setHealth(100);
                player.setPosX(100);
                player.setPosY(400);
            }
        }
    }
}

void Employee::resetSuspicion()
{
    suspicion = 0.f;
    suspicionTimer = 0.f;
}
