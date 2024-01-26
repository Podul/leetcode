/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
char* longestPalindrome(char* s) {
    int len = strlen(s);

    int **dp = malloc(sizeof(int*) * len);
    for (int i=0; i<len; i++) {
        dp[i] = malloc(sizeof(int) * len);
    }

    int maxLen = 0;
    int maxI = 0;
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            if (s[i] != s[len-j-1]) {
                dp[i][j] = 0;
                continue;
            }
            if (i-1 < 0 || j-1 < 0) {
                dp[i][j] = 1;
            }else {
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            int end = len - j - 1;
            int start = i - dp[i][j] + 1;
            if (start == end && maxLen < dp[i][j]) {
                maxLen = dp[i][j];
                maxI = i;
            }
        }
    }

    char *result = malloc(sizeof(char) * (maxLen + 1));
    result[maxLen] = '\0';
    maxLen--;
    for (; maxLen>=0; maxI--, maxLen--) {
        result[maxLen] = s[maxI];
    }

    return result;
}
// @lc code=end


#ifdef MINUNIT_MINUNIT_H
MU_TEST(test_longest_palindrome_substring_1) {
    char *s = "babad";
    char *result = "bab";
    char *output = longestPalindrome(s);
    mu_assert_string_eq(result, output);
    free(output);
}

MU_TEST(test_longest_palindrome_substring_2) {
    char *s = "cbbd";
    char *result = "bb";
    char *output = longestPalindrome(s);
    mu_assert_string_eq(result, output);
    free(output);
}

MU_TEST(test_longest_palindrome_substring_3) {
    char *s = "aacabdkacaa";
    char *result = "aca";
    char *output = longestPalindrome(s);
    mu_assert_string_eq(result, output);
    free(output);
}



MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_longest_palindrome_substring_1);
    MU_RUN_TEST(test_longest_palindrome_substring_2);
    MU_RUN_TEST(test_longest_palindrome_substring_3);
}
#endif