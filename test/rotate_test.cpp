#include "gtest/gtest.h"

#include "Rotate.h"
#include "SimpleIRotable.h"

TEST(RotateTest, Rotate)
{
    SimpleIRotable spaceship(0, 20, 360);
    Rotate rotate_command(&spaceship);
    rotate_command.Execute();

    EXPECT_EQ(spaceship.GetDirection(), 20);
}

TEST(RotateTest, CheckInitParams)
{
    SimpleIRotable spaceship(0, 20, 360);
    EXPECT_EQ(spaceship.GetDirection(), 0);
    EXPECT_EQ(spaceship.GetAngularVelocity(), 20);
    EXPECT_EQ(spaceship.GetMaxDirections(), 360);
}