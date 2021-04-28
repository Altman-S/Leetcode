// created by Pi on 28/4/2021
// 环形链表2
// input: head = [3,2,0,-4], pos = 1
// output: 返回索引为1的链表节点


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针法，快慢指针  O(n) O(1)
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head和相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode *index1 = head;
                ListNode *index2 = slow;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};


// 哈希表  O(n) O(n)
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        
    }
};