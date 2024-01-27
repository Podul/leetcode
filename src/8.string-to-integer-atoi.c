/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
int myAtoi(char* s) {
    int num = 0;
    bool isStarted = false;
    int symbol = 1;
    int maxNum = INT_MAX;
    for(; *s; ++s) {
        if (!isStarted) {
            if (*s == '-') {
                isStarted = true;
                symbol = -1;
                maxNum = INT_MIN;
            }else if (*s == '+') {
                isStarted = true;
            }else if(*s >= '0' && *s <= '9') {
                isStarted = true;
                goto START;
            }else if (*s == ' ') {
                continue;
            }else {
                break;
            }
            continue;
        }

        START:
        if (*s < '0' || *s > '9') {
            break;
        }
        int val = *s - '0';
        if (!num && !val) {
            continue;
        }

        if (num > maxNum / 10 * symbol || (num == maxNum / 10 * symbol && val >= maxNum % 10 * symbol)) {
            return symbol < 0 ? INT_MIN : INT_MAX;
        }

        num *= 10;
        num += val;
    }
    return num * symbol;
}
// @lc code=end


#ifdef MINUNIT_MINUNIT_H
MU_TEST(test_string_to_integer_atoi_1) {
    char *s = "42";
    int result = 42;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_2) {
    char *s = "   -42";
    int result = -42;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_3) {
    char *s = "4193 with words";
    int result = 4193;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}


MU_TEST(test_string_to_integer_atoi_4) {
    char *s = "words and 987";
    int result = 0;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}


MU_TEST(test_string_to_integer_atoi_5) {
    char *s = "-91283472332";
    int result = -2147483648;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_6) {
    char *s = "21474836460";
    int result = 2147483647;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_7) {
    char *s = "  0000000000012345678";
    int result = 12345678;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_8) {
    char *s = "00000-42a1234";
    int result = 0;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_9) {
    char *s = "2147483646";
    int result = 2147483646;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST(test_string_to_integer_atoi_10) {
    char *s = "-2147483648";
    int result = -2147483648;
    int output = myAtoi(s);
    mu_assert_int_eq(result, output);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_string_to_integer_atoi_1);
    MU_RUN_TEST(test_string_to_integer_atoi_2);
    MU_RUN_TEST(test_string_to_integer_atoi_3);
    MU_RUN_TEST(test_string_to_integer_atoi_4);
    MU_RUN_TEST(test_string_to_integer_atoi_5);
    MU_RUN_TEST(test_string_to_integer_atoi_6);
    MU_RUN_TEST(test_string_to_integer_atoi_7);
    MU_RUN_TEST(test_string_to_integer_atoi_8);
    MU_RUN_TEST(test_string_to_integer_atoi_9);
    MU_RUN_TEST(test_string_to_integer_atoi_10);
}
#endif