#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payroll_tests, when_hours_greater_than_40){
    EXPECT_EQ(40, get_reg_hours(50));
}

TEST(payroll_tests, when_hours_less_than_0){
    EXPECT_EQ(0, get_reg_hours(-10));
}


