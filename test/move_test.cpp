#include "gtest/gtest.h"

#include "SimpleIMovable.h"
#include "Move.h"

#include "ErrorIMovable.h"

TEST(MoveTest, Move)
{
    SimpleIMovable spaceship(Vector(12, 5), Vector(-7, 3));
    Move move_command(&spaceship);
    move_command.Execute();
    EXPECT_EQ(spaceship.GetPosition(), Vector(5, 8));
}

TEST(MoveTest, CheckPositionAndVelocity)
{
    SimpleIMovable spaceship(Vector(12, 5), Vector(-7, 3));
    EXPECT_EQ(spaceship.GetPosition(), Vector(12, 5));
    EXPECT_EQ(spaceship.GetVelocity(), Vector(-7, 3));
}

TEST(MoveTest, GetPositionError)
{
    ErrorIMovable spaceship(Vector(12, 5), Vector(-7, 3));
    Move move_command(&spaceship);

    ASSERT_THROW(
        {
            move_command.Execute();
        },
        std::runtime_error);
}
