#include <iostream>

using namespace std;

class Node {
public:
    Node *next;
    int data;
};


class HeadNode {
public:
    Node *last;
    Node *head;


    HeadNode(int data) {
        this->head = new Node();
        this->head->data=data;
        this->last = this->head;
        this->head->next = nullptr;
    }

    void insertLast(int data) {
        Node *temp = new Node();
        temp->data = data;
        temp->next = nullptr;



        this->last->next = temp;
        this->last = temp;
    }

    void removeFirst() {
        if(this->head == nullptr) {
            cout << "Nothing to remove";
            return;
        }

        if(this->last == this->head) {
            delete this->head;
            this->head = nullptr;
            this->last = nullptr;
            return;
        }

        Node *temp=head;
        this->head=this->head->next;
        delete temp;
    }


    void removeLast() {
        if(this->head == nullptr) {
            cout << "Nothing to remove";
            return;
        }

        if(this->last == this->head) {

            delete this->head;
            this->head = nullptr;
            this->last = nullptr;
            return;
        }



    }

    void showItems() {
        Node *temp = this->head;
        if(this->head == nullptr) {
            cout << "empty";
        }
        do {
            cout << temp->data;
            temp = temp->next;
            if(temp != nullptr)
                cout << " -> ";
        }while(temp != nullptr);

    }

};

int main()
{
    HeadNode *n = new HeadNode(10);
    n->insertLast(20);
    n->insertLast(30);
    n->removeLast();
    //bool a  = (n->head->next) == nullptr;
    cout << "DATA ";
    n->showItems();

    return 0;
}
