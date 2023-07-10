#pragma once

#include "IRotable.h"

class SimpleIRotable : public IRotable
{
public:
    SimpleIRotable(int direction, int angular_velocity, int max_directions) : direction_(direction),
                                                                              angular_velocity_(angular_velocity),
                                                                              max_directions_(max_directions)
    {
    }
    int GetDirection() override
    {
        return direction_;
    }
    void SetDirection(int direction) override
    {
        direction_ = direction;
    }
    int GetAngularVelocity() override
    {
        return angular_velocity_;
    }
    int GetMaxDirections() override
    {
        return max_directions_;
    }

private:
    int direction_ = 0;
    int angular_velocity_ = 0;
    int max_directions_ = 360;
};