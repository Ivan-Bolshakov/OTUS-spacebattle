#pragma once
#include "Vector.h"

class IMovable
{
public:
    virtual Vector GetPosition() = 0;
    virtual void SetPosition(const Vector &position) = 0;
    virtual Vector GetVelocity() = 0;
    virtual void SetVelocity(const Vector &velocity) = 0;
};