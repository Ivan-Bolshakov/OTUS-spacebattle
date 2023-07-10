#pragma once

class IRotable
{
public:
	virtual int GetDirection() = 0;
	virtual void SetDirection(int direction) = 0;
	virtual int GetAngularVelocity() = 0;
	virtual int GetMaxDirections() = 0;
};