#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
    ListNode(): data(0), next(nullptr) {}
    ListNode(int val): data(val), next(nullptr) {}
    ListNode(int val, ListNode* next): data(val), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}


// 92
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0, head);
    // cache the node before left node
    ListNode* before = dummy;
    ListNode* cur = head;
    // keep forward, at last cur = left node
    for (int i = 1; i < left; i++) {
        ListNode* nxt = cur->next;
        before = cur;
        cur = nxt;
    }
    before->next = cur;

    // reverse list, at last cur = node after right node, prev = right, new head
    ListNode* prev = nullptr;
    for (int i = left; i <= right; i++) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    // link new list
    before->next->next = cur;
    before->next = prev;
    
    // return
    return dummy->next;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = new ListNode(arr[0], nullptr);
    ListNode* pre = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* cur = new ListNode(arr[i]);
        pre->next = cur;
        pre = cur;
    }

    // ListNode* reversed = reverseList(head);
    ListNode* reversed = reverseBetween(head, 2, 4);

    ListNode* cur = reversed;
    while (cur != nullptr) {
        cout << cur->data << ", " << endl;
        cur = cur-> next;
    }

    return 0;
}