#pragma once
#include "ICommand.h"
#include "IRotable.h"

class Rotate : public ICommand
{
public:
    Rotate(IRotable *rotable) : rotable_(rotable)
    {
    }
    void Execute()
    {
        rotable_->SetDirection(
            (rotable_->GetDirection() + rotable_->GetAngularVelocity()) % rotable_->GetMaxDirections());
    }

private:
    IRotable *rotable_;
};