#pragma once

class IFuelable
{
public:
    virtual unsigned long GetFuelLevel() const = 0;
    virtual void SetFuelLevel(unsigned long) = 0;

    virtual unsigned long GetFuelCost() const = 0;
    virtual void SetFuelCost(unsigned long) = 0;
};