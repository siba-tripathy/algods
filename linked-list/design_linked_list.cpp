class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;
    int sz;

public:
    MyLinkedList() {
        head = nullptr;
        sz = 0;
    }

    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        Node* cur = head;
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        sz++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        sz++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        sz++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) return;
        if (index == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
        sz--;
    }
};
