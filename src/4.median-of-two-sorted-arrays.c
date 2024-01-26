/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    double result = 0;
    int size = nums1Size + nums2Size;
    bool isOdd = !(size % 2);

    while(i+j <= size/2) {
        if ((isOdd && i+j == size/2-1) || (!isOdd && i+j == size/2)) {
            result = 0;
        }
        if (i < nums1Size && j < nums2Size) {
            if (nums1[i] < nums2[j]) {
                result += nums1[i];
                i ++;
            }else {
                result += nums2[j];
                j ++;
            }
        }else if (j >= nums2Size) {
            result += nums1[i];
            i ++;
        }else if (i >= nums1Size) {
            result += nums2[j];
            j ++;
        }else {
            break;
        }
    }

    return isOdd ? result / 2 : result;
}
// @lc code=end

#ifdef MINUNIT_MINUNIT_H
MU_TEST(test_median_of_two_sorted_arrays_1) {
    int nums1[] = { 1, 3 };
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = { 2 };
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    double result = 2.0;

    double output = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    mu_assert_double_eq(result, output);
}

MU_TEST(test_median_of_two_sorted_arrays_2) {
    int nums1[] = { 1, 2 };
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = { 3, 4 };
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    double result = 2.50;

    double output = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    mu_assert_double_eq(result, output);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_median_of_two_sorted_arrays_1);
    MU_RUN_TEST(test_median_of_two_sorted_arrays_2);
}
#endif