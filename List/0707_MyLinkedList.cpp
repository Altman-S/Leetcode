// created by Pi on 27/4/2021
// 设计链表
// MyLinkedList linkedList = new MyLinkedList();
// linkedList.addAtHead(1);
// linkedList.addAtTail(3);
// linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
// linkedList.get(1);            //返回2
// linkedList.deleteAtIndex(1);  //现在链表是1-> 3
// linkedList.get(1);            //返回3


class MyLinkedList {
public:
    // 定义链表结构体
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int v) : val(v), next(nullptr) { }
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummyhead = new LinkedNode(0);  // 虚拟头节点
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        LinkedNode *curr = _dummyhead;  // 辅助节点
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        while (index >= 0) {  // 一直往后移
            curr = curr->next;
            index--;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode *addhead = new LinkedNode(val);  // 添加的新节点
        addhead->next = _dummyhead->next;  // 插入新节点
        _dummyhead->next = addhead;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode *addtail = new LinkedNode(val);  // 添加的新节点
        LinkedNode *curr = _dummyhead;
        while (curr->next != NULL) {  // 搜索到链表的尾端
            curr = curr->next;
        } 
        curr->next = addtail;  // 在尾端插入新节点
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        LinkedNode *addindex = new LinkedNode(val);  // 添加的新节点
        LinkedNode *curr = _dummyhead;
        if (index <= _size) {
            while (index > 0) {
                curr = curr->next;
                index--;
            }
            addindex->next = curr->next;  // 在第index个节点之前插入新节点
            curr->next = addindex;
            _size++;
        }  
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        LinkedNode *deleteindex = _dummyhead;  // 辅助节点
        if (index >= 0 && index < _size) {
            while (index > 0) {
                deleteindex = deleteindex->next;  //deleteAtIndex指向需要删除节点的前一个节点
                index--;
            }
            LinkedNode *tmp = deleteindex->next;
            deleteindex->next = deleteindex->next->next;
            delete tmp;
            _size--;
        }      
    }
private:
    int _size;
    LinkedNode *_dummyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */