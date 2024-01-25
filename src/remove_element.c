int removeElement(int* nums, int numsSize, int val) {
    int offset = 0;
    for (int i=0; i<numsSize; i++) {
        int num = nums[i];
        if (num == val) {
            offset++;
        }else {
            nums[i - offset] = nums[i];
        }
    }
    return numsSize - offset;
}

#ifdef MINUNIT_MINUNIT_H
MU_TEST_SUITE(test_suite) {}
#endif