// created by Pi on 28/4/2021
// 删除链表的倒数第N个节点
// input: head = [1,2,3,4,5], n = 2
// output: [1,2,3,5]


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

// 双指针法  O(L) O(1)
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *slowptr = dummyHead;
        ListNode *fastptr = dummyHead->next;
        ListNode *temp;

        while (n--) {
            fastptr = fastptr->next;  // fastptr - slowptr == n + 1
        }

        while (fastptr != NULL) {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        
        temp = slowptr->next;
        slowptr->next = slowptr->next->next;
        delete temp;

        return dummyHead->next;       
    }
};


// 栈  O(L) O(L)
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode *curr = dummyHead;

        while (curr) {
        	stk.push(curr);
        	curr = curr->next;
        }
        for (int i = 0; i < n; i++) {
        	stk.pop();
        }

        ListNode *prev = stk.top();  // 所删除节点的前一个节点
        prev->next = prev->next->next;
        // ListNode *temp = prev->next;
        // delete temp;  // 不知道这条语句哪里出了问题

        return dummyHead->next;
};