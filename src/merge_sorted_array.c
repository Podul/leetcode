// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
// 88. Merge Sorted Array


#include "stdio.h"

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
