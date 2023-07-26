#pragma once

#include "IFuelable.h"

class SimpleFuelable : public IFuelable
{
public:
    SimpleFuelable(unsigned long fuel, unsigned long fuel_cost) : fuel_(fuel), fuel_cost_(fuel_cost)
    {
    }

    unsigned long GetFuelLevel() const override
    {
        return fuel_;
    }
    void SetFuelLevel(unsigned long fuel) override
    {
        fuel_ = fuel;
    }
    unsigned long GetFuelCost() const override
    {
        return fuel_cost_;
    }
    void SetFuelCost(unsigned long fuel_cost) override
    {
        fuel_cost_ = fuel_cost;
    }

private:
    unsigned long fuel_;
    unsigned long fuel_cost_;
};