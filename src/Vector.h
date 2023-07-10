#pragma once

#include <ostream>

class Vector
{
public:
    double x_;
    double y_;

    Vector() : x_(0), y_(0) {}
    Vector(double x, double y) : x_(x), y_(y) {}

    Vector operator+(const Vector &v) const { return Vector(x_ + v.x_, y_ + v.y_); }
    Vector &operator+=(const Vector &v)
    {
        x_ += v.x_;
        y_ += v.y_;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector &v);
};

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << '{' << v.x_ << ", " << v.y_ << '}';
    return os;
}

bool operator==(const Vector &v1, const Vector &v2)
{
    return v1.x_ == v2.x_ && v1.y_ == v2.y_;
}