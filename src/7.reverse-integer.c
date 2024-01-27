/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start
int reverse(int x){
    int max = x < 0 ? INT_MIN : INT_MAX;
    int symbol = x < 0 ? -1 : 1;
    int scale = 1000000000;
    int num = 0;
    int mayZero = -1;
    while(x) {
        int val = x % 10;
        x /= 10;

        if (mayZero == -1 && val * symbol > max / scale * symbol) {
            mayZero = 1;
        }else if (mayZero == -1 && val * symbol < max / scale * symbol) {
            mayZero = 0;
        }

        max -= (max / scale) * scale;
        scale /= 10;

        if (mayZero == 1 && !max) {
            return 0;
        }

        if (num || val) {
            num = num * 10 + val;
        }
    }

    return num;
}
// @lc code=end


#ifdef MINUNIT_MINUNIT_H
MU_TEST(test_reverse_integer_1) {
    int x = 123;
    int result = 321;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_2) {
    int x = -123;
    int result = -321;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_3) {
    int x = 120;
    int result = 21;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_4) {
    int x = 1534236469;
    int result = 0;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_5) {
    int x = 1534236469;
    int result = 0;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_6) {
    int x = 2147483647;
    int result = 0;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_7) {
    int x = -2147483648;
    int result = 0;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_reverse_integer_8) {
    int x = -2147483412;
    int result = -2143847412;
    int output = reverse(x);
    mu_assert_int_eq(result, output);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_reverse_integer_1);
    MU_RUN_TEST(test_reverse_integer_2);
    MU_RUN_TEST(test_reverse_integer_3);
    MU_RUN_TEST(test_reverse_integer_4);
    MU_RUN_TEST(test_reverse_integer_5);
    MU_RUN_TEST(test_reverse_integer_6);
    MU_RUN_TEST(test_reverse_integer_7);
    MU_RUN_TEST(test_reverse_integer_8);
}
#endif