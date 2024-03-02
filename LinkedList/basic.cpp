
#include <vector>
#include <iostream>

using namespace std;


struct Node {
public:
    int val;
    Node* next;

    // default constructor
    Node() {
        val = 0;
        next = NULL;
    }
    // constructor
    Node(int data) {
        this->val  = data;
        this->next = NULL;
    }

};


class LinkedList {
private:
    Node* head;

public:
    // default constructor
    LinkedList() {head = NULL;}

    // insert
    void insertNode(int data){
        // create new Node
        Node* newNode = new Node(data);
        // empty list
        if (head == NULL) {
            head = newNode;
            return;
        }
        // loop till list end
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // append to end
        temp->next = newNode;
        
    }

    // display
    void printList(){
        Node* temp = head;
        if (head == NULL) {
            cout << "Empty list!" << endl;
            return;
        }
        cout << "List: " << endl;
        while (temp!= NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // get kth element from end
    int getKthEnd(int k){
        Node* fast = head;
        Node* slow = head;
        // move fast pointer foward
        for (int i=0; i<k-1; i++) {
            if (fast == NULL) return 0;
            fast = fast->next;
        }
        // move fast and slow together
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }

};


int main(){

    // test data
    vector<int> vals;
    vals = {3, 7, 3, 4};

    // init
    LinkedList list1;
    for (auto & val : vals) {
        list1.insertNode(val);
    }

    // print
    list1.printList();

    // find kth element from end
    cout << "Found node val: " << list1.getKthEnd(3) << endl;

    return 0;   
}