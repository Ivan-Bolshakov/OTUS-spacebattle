#pragma once
#include <exception>

class CommandException : public std::exception
{
public:	
	virtual char const* what() const noexcept  override
	{
		return "CommandException";
	}
};
