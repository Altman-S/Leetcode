// created by Pi on 28/4/2021
// 反转链表
// input: head = [1,2,3,4,5]
// output: [5,4,3,2,1]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 双指针法  O(n) O(1)
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;  // 利用双指针的移动
        ListNode *curr = head;
        ListNode *tmp;  // 保存前一阶段的prev指针

        while (curr != NULL) {
            tmp = prev;
            prev = curr;
            curr = curr->next;
            prev->next = tmp;        
        }

        return prev;
    }
};


// 递归法  O(n) O(n)
class Solution2 {
public:
    ListNode* reverse(ListNode* prev, ListNode* curr) {
        if (curr == NULL) return prev;
        ListNode *tmp = curr->next;
        curr->next = prev;
        // 下面的语句相当于:
        // prev = curr;
        // curr = tmp;
        return reverse(curr, tmp);
    }

    ListNode* reverseList(ListNode* head) {
        // 和双指针初始化一样的逻辑
        // ListNode *prev = NULL;
        // LIstNode *curr = head;
        return reverse(NULL, head);
    }
};