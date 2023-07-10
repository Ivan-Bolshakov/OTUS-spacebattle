#pragma once
#include "IMovable.h"
#include "Vector.h"

class SimpleIMovable : public IMovable
{
public:
    SimpleIMovable(const Vector &position, const Vector &velocity)
        : position_(position),
          velocity_(velocity)
    {
    }
    Vector GetPosition() override
    {
        return position_;
    }
    void SetPosition(const Vector &position) override
    {
        position_ = position;
    }
    Vector GetVelocity() override
    {
        return velocity_;
    }
    void SetVelocity(const Vector &velocity) override
    {
        velocity_ = velocity;
    }

private:
    Vector position_ = {};
    Vector velocity_ = {};
};