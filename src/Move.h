#pragma once
#include "ICommand.h"
#include "IMovable.h"

class Move : public ICommand
{
public:
    Move(IMovable *movable) : movable_(movable)
    {
    }
    void Execute()
    {
        movable_->SetPosition(movable_->GetPosition() + movable_->GetVelocity());
    }

private:
    IMovable *movable_;
};