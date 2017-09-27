#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payroll_tests, when_hours_greater_than_40){
    EXPECT_EQ(40, get_reg_hours(50));
}

TEST(payroll_tests, when_hours_less_than_0){
    EXPECT_EQ(0, get_reg_hours(-10));
}

TEST(ot_hours, when_total_hours_greater_than_standard_hours){
    EXPECT_EQ(10, get_ot_hours(50));
}

TEST(ot_hours, when_total_hours_less_than_standard_hours){
    EXPECT_EQ(0, get_ot_hours(30));
}


