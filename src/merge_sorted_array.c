// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
// 88. Merge Sorted Array



// 比较 nums1 和 nums2 的最大值，并将其放在 nums1 的最后
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;
	int p2 = n - 1;
	int p = m + n - 1;

	while (p2 >= 0) {
		int num2 = nums2[p2];

		if (p1 >= 0 && nums1[p1] > num2) {
			nums1[p] = nums1[p1];
			p1--;
		}else {
			nums1[p] = num2;
			p2--;
		}
		p--;
	}
}

#ifdef MINUNIT_MINUNIT_H

MU_TEST(test_merge_sorted_array1) {
   int nums1[] = {1,2,3,0,0,0};
   int nums1Size = 6;
   int m = 3;
   int nums2[] = {2,5,6};
   int nums2Size = 3;
   int n = 3;
   merge(nums1, nums1Size, m, nums2, nums2Size, n);    
   int result[] = {1,2,2,3,5,6};

   for (int i = 0; i<nums1Size; i++) {
      mu_assert_int_eq(nums1[i], result[i]);
   }
}

MU_TEST(test_merge_sorted_array2) {
   int nums1[] = {1};
   int nums1Size = 1;
   int m = 1;
   int nums2[] = {};
   int nums2Size = 0;
   int n = 0;
   merge(nums1, nums1Size, m, nums2, nums2Size, n);    
   int result[] = {1};

   for (int i = 0; i<nums1Size; i++) {
      mu_assert_int_eq(nums1[i], result[i]);
   }
}

MU_TEST(test_merge_sorted_array3) {
   int nums1[] = {0};
   int nums1Size = 1;
   int m = 0;
   int nums2[] = {1};
   int nums2Size = 1;
   int n = 1;
   merge(nums1, nums1Size, m, nums2, nums2Size, n);    
   int result[] = {1,2,2,3,5,6};

   for (int i = 0; i<nums1Size; i++) {
      mu_assert_int_eq(nums1[i], result[i]);
   }
}

MU_TEST_SUITE(test_suite) {
   MU_RUN_TEST(test_merge_sorted_array1);
   MU_RUN_TEST(test_merge_sorted_array2);
   MU_RUN_TEST(test_merge_sorted_array3);
}
#endif