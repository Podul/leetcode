/*
 * @lc app=leetcode id=303 lang=c
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start



typedef struct {
    int *nums;
    int numsSize;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *arr = malloc(sizeof(NumArray));
    arr->nums = malloc(sizeof(int) * numsSize);
    arr->numsSize = numsSize;
    for (int i=0; i<numsSize; i++) {
        arr->nums[i] = nums[i];
    }
    return arr;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int totals = 0;
    for (int i=left; i<=right; i++) {
        totals += obj->nums[i];
    }
    return totals;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
// @lc code=end

