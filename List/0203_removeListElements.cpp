// created by Pi on 27/4/2021
// 移除链表元素
// input: head = [1,2,6,3,4,5,6], val = 6
// output: [1,2,3,4,5]


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

// 直接使用原来的链表 O(n) O(1)
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头节点
        while (head != NULL && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp; 
        }

        // 删除非头节点
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};


// 设置一个虚拟头节点
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 设置一个虚拟头节点
        ListNode* p = new ListNode(0, head);
        ListNode* curr = p;

        while (curr != NULL && curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;
            }
            else {
                curr = curr->next;
            }
        }

        return p->next;
    }
};


