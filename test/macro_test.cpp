#include "gtest/gtest.h"

#include "BurnFuel.h"
#include "CheckFuel.h"
#include "SimpleFuelable.h"
#include "SimpleIMovable.h"
#include "Move.h"
#include "MacroCommand.h"

TEST(MacroCommand, MacroCommandMove)
{
    SimpleFuelable fuelable(15, 10);
    BurnFuel burn_command(&fuelable);
    CheckFuel check_command(&fuelable);
    SimpleIMovable spaceship(Vector(12, 5), Vector(-7, 3));
    Move move_command(&spaceship);
    std::vector<ICommand *> cmds;
    cmds.push_back(&check_command);
    cmds.push_back(&move_command);
    cmds.push_back(&burn_command);
    MacroCommand commands(cmds);
    commands.Execute();
    EXPECT_EQ(spaceship.GetPosition(), Vector(5, 8));
    EXPECT_EQ(fuelable.GetFuelLevel(), 5);
}

TEST(MacroCommand, MacroCommandMoveException)
{
    SimpleFuelable fuelable(15, 10);
    BurnFuel burn_command(&fuelable);
    CheckFuel check_command(&fuelable);
    SimpleIMovable spaceship(Vector(12, 5), Vector(-7, 3));
    Move move_command(&spaceship);
    std::vector<ICommand *> cmds;
    cmds.push_back(&check_command);
    cmds.push_back(&move_command);
    cmds.push_back(&burn_command);
    MacroCommand commands(cmds);
    commands.Execute();
    ASSERT_THROW(
        {
            commands.Execute();
        },
        std::exception);
}
