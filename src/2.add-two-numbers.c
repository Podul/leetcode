/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *root = NULL;
    struct ListNode *current = NULL;
    bool needAddOne = false;
    while (l1 || l2) {
        int val = 0;
        if (l1) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val += l2->val;
            l2 = l2->next;
        }
        if (needAddOne) {
            val++;
            needAddOne = false;
        }
        if (val > 9) {
            needAddOne = true;
            val = val % 10;
        }
        if (current) {
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
            current->val = val;
            current->next = NULL;
        }else{
            root = malloc(sizeof(struct ListNode));
            current = root;
            current->val = val;
            current->next = NULL;
        }
    }
    if (needAddOne) {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = 1;
        current->next = NULL;
    }
    return root;
}
// @lc code=end


#ifdef MINUNIT_MINUNIT_H

struct ListNode* initListNode(int *nums, int numsSize) {
    struct ListNode* root, *current = NULL;
    for (int i=0; i<numsSize; i++) {
        if (current) {
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
        }else {
            root = malloc(sizeof(struct ListNode));
            current = root;
        }
        current->val = nums[i];
        current->next = NULL;
    }
    return root;
}

MU_TEST(test_1) {
    int nums1[] = { 2, 4, 3 };
    int nums2[] = { 5, 6, 4 };
    int nums[] = { 7, 0, 8 };
    int numsSize = sizeof(nums) / sizeof(int);

    struct ListNode* l1 = initListNode(nums1, sizeof(nums1) / sizeof(int));
    struct ListNode* l2 = initListNode(nums2, sizeof(nums2) / sizeof(int));

    struct ListNode* output = addTwoNumbers(l1, l2);
    struct ListNode* cur = output;

    printf("output: ");
    while(cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");

    printf("result: ");
    for (int i=0; i<numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int i = 0;
    cur = output;
    while(cur && i < numsSize) {
        mu_assert_int_eq(cur->val, nums[i]);
        i++;
        cur = cur->next;
    }

    if (cur || i < numsSize) {
        mu_fail("output not eq result");
    }

    for (;l1;l1=l1->next) {
        free(l1);
    }
    for (;l2;l2=l2->next) {
        free(l2);
    }
    for (;output;output=output->next) {
        free(output);
    }
}

MU_TEST_SUITE(test_suite) {
   MU_RUN_TEST(test_1);
}

#endif