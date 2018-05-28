#include <iostream>
#include "gtest/gtest.h"

#include "project1.h"

#include <cmath>


TEST(libapp, test_numbers_sum1)
{
	char s[] = "2+2";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 4);
}

TEST(libapp, test_numbers_sum2)
{
	char s[] = "2+2";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 100);
}

TEST(libapp, test_breckets_numbers_sub_mult)
{
	char s[] = "2*(2-2)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 0);
}

TEST(libapp, test_breckets_numbers_sub_mult2)
{
	char s[] = "2*(2-2)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 0);
}

TEST(libapp, test_brackets_and_numbers)
{
	char s[] = "2+10/(1+4)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 4);
}

TEST(libapp, test_brackets_and_numbers2)
{
	char s[] = "2+10/(1+4)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 100);
}

TEST(libapp, test_brackets_and_numbers_2)
{
	char s[] = "2+10/-(1+4)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 0);
}

TEST(libapp, test_brackets_and_numbers_22)
{
	char s[] = "2+10/-(1+4)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 0);
}

TEST(libapp, test_brackets_and_number)
{
	char s[] = "(2)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 2);
}

TEST(libapp, test_brackets_and_number2)
{
	char s[] = "(2)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 10);
}

TEST(libapp, test_brackets_and_numbers_sum)
{
	char s[] = "(2+2)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 4);
}

TEST(libapp, test_brackets_and_numbers_sum2)
{
	char s[] = "(2+2)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 100);
}

TEST(libapp, test_brackets_and_numbers_sub)
{
	char s[] = "(2-2)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 0);
}

TEST(libapp, test_brackets_and_numbers_sub2)
{
	char s[] = "(2-2)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 0);
}

TEST(libapp, test_brackets_and_numbers_mult)
{
	char s[] = "(2*2)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 4);
}

TEST(libapp, test_brackets_and_numbers_mult2)
{
	char s[] = "(2*2)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 100);
}

TEST(libapp, test_brackets_and_numbers_div)
{
	char s[] = "(2/2)";
	double res;

	res = calculate(s, NULL);
	convert(res);
	ASSERT_EQ(res, 1);
}

TEST(libapp, test_brackets_and_numbers_div2)
{
	char s[] = "(2/2)";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, 1);
}

TEST(libapp, error_convert)
{
	char s[] = "-2-2";
	double res2, res;
	res = calculate(s, NULL);
	res2 = convert(res);
	ASSERT_EQ(res2, -1);
}
