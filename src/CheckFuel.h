#pragma once
#include "ICommand.h"
#include "CommandException.h"
#include "IFuelable.h"

class CheckFuel : public ICommand
{
public:
	CheckFuel(IFuelable* fuel) : fuel_(fuel)
	{

	}
	void Execute()
	{
		if (fuel_->GetFuelLevel() < fuel_->GetFuelCost())
			throw CommandException();
	}
private:
	IFuelable *fuel_;
};