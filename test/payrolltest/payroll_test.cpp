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

TEST(gross_pay, gross_pay_with_no_ot_hours){
    EXPECT_EQ(800, get_gross_pay(40, 0, 20));
}

TEST(gross_pay, gross_pay_with_ot_hours){
    EXPECT_EQ(950, get_gross_pay(40, 5, 20));
}

TEST(gross_pay, gross_pay_with_salary){
    EXPECT_EQ(50000, get_gross_pay(50000));
}
