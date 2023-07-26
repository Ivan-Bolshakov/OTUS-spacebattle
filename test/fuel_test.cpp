#include "gtest/gtest.h"

#include "BurnFuel.h"
#include "CheckFuel.h"
#include "SimpleFuelable.h"

TEST(FuelTest, BurnFuel)
{
    SimpleFuelable fuelable(10, 2);
    BurnFuel burn_command(&fuelable);

    EXPECT_EQ(fuelable.GetFuelLevel(), 10);
    EXPECT_EQ(fuelable.GetFuelCost(), 2);

    burn_command.Execute();

    EXPECT_EQ(fuelable.GetFuelLevel(), 8);
}

TEST(FuelTest, CheckFuel)
{
    SimpleFuelable fuelable(10, 2);
    CheckFuel check_command(&fuelable);
    EXPECT_EQ(fuelable.GetFuelLevel(), 10);
    EXPECT_EQ(fuelable.GetFuelCost(), 2);

    check_command.Execute();

    EXPECT_EQ(fuelable.GetFuelLevel(), 10);
    EXPECT_EQ(fuelable.GetFuelCost(), 2);
}

TEST(FuelTest, CheckFuelExeption)
{
    SimpleFuelable fuelable(1, 20);
    CheckFuel check_command(&fuelable);
    EXPECT_EQ(fuelable.GetFuelLevel(), 1);
    EXPECT_EQ(fuelable.GetFuelCost(), 20);
    ASSERT_THROW(
        {
            check_command.Execute();
        },
        std::exception);
}

TEST(FuelTest, BurnCheckFuel)
{
    SimpleFuelable fuelable(15, 10);
    BurnFuel burn_command(&fuelable);
    CheckFuel check_command(&fuelable);
    burn_command.Execute();
    EXPECT_EQ(fuelable.GetFuelLevel(), 5);
    EXPECT_EQ(fuelable.GetFuelCost(), 10);
    ASSERT_THROW(
        {
            check_command.Execute();
        },
        std::exception);
}