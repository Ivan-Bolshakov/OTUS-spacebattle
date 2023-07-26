#pragma once
#include "ICommand.h"
#include <vector>
#include <utility>

class MacroCommand : public ICommand
{
public:
	MacroCommand(std::vector<ICommand*> cmds) : cmds_(std::move(cmds))
	{

	}
	void Execute()
	{		
		for (ICommand* cmd : cmds_)
		{
			cmd->Execute();
		}
	}
private:
	std::vector<ICommand*> cmds_;
};