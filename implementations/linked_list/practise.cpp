#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int val) {
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; i++)
            temp = temp->next;
        if (!temp) {
            cout << "Position out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int pos) {
        if (!head) return;
        if (pos == 0) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp->next && i < pos - 1; i++)
            temp = temp->next;
        if (!temp->next) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;
    DNode* tail;

    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteAtBeginning() {
        if (!head) return;
        DNode* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!tail) return;
        DNode* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void displayForward() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        DNode* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};


class CSNode {
public:
    int data;
    CSNode* next;
    CSNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularSinglyLinkedList {
public:
    CSNode* head;
    CircularSinglyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        CSNode* newNode = new CSNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CSNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key && head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        CSNode *last = head, *d = NULL;
        if (head->data == key) {
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            d = head;
            head = head->next;
            delete d;
            return;
        }
        CSNode* temp = head;
        while (temp->next != head && temp->next->data != key)
            temp = temp->next;
        if (temp->next->data == key) {
            d = temp->next;
            temp->next = temp->next->next;
            delete d;
        }
    }

    void display() {
        if (!head) return;
        CSNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};


class CDNode {
public:
    int data;
    CDNode* next;
    CDNode* prev;
    CDNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class CircularDoublyLinkedList {
public:
    CDNode* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        CDNode* newNode = new CDNode(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        CDNode* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        CDNode* curr = head, *prevNode = NULL;
        while (curr->data != key) {
            if (curr->next == head) {
                cout << "Key not found\n";
                return;
            }
            prevNode = curr;
            curr = curr->next;
        }
        if (curr->next == head && curr->prev == head) {
            head = NULL;
            delete curr;
            return;
        }
        if (curr == head)
            head = head->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    void display() {
        if (!head) return;
        CDNode* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};


int main() {
    SinglyLinkedList sll;
    sll.insertAtEnd(10);
    sll.insertAtEnd(20);
    sll.insertAtBeginning(5);
    sll.display();

    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtBeginning(0);
    dll.displayForward();

    CircularSinglyLinkedList csll;
    csll.insertAtEnd(11);
    csll.insertAtEnd(22);
    csll.insertAtEnd(33);
    csll.display();

    CircularDoublyLinkedList cdll;
    cdll.insertAtEnd(100);
    cdll.insertAtEnd(200);
    cdll.insertAtEnd(300);
    cdll.display();

    return 0;
}
