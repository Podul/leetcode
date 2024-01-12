#include "../include/minunit.h"
#include "../src/arithmetic.h"


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

int main(void) {
   MU_RUN_SUITE(test_suite);
   MU_REPORT();
   return MU_EXIT_CODE; 
}
