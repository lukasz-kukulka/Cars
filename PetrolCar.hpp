#pragma once

#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : public Car
{
public:
    PetrolCar(Engine* engine);
    ~PetrolCar();
    void changeGear(int gear, PetrolEngine & petrolEngine);
};

