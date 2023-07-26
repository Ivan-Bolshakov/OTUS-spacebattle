#pragma once
#include "ICommand.h"
#include "CommandException.h"
#include "IFuelable.h"

class BurnFuel : public ICommand
{
public:
	BurnFuel(IFuelable *fuel) : fuel_(fuel)
	{
	}
	void Execute()
	{
		if (fuel_->GetFuelLevel() > fuel_->GetFuelCost())
			fuel_->SetFuelLevel(fuel_->GetFuelLevel() - fuel_->GetFuelCost());
		else
			fuel_->SetFuelLevel(0);
	}

private:
	IFuelable *fuel_;
};