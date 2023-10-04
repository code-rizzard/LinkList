#include <iostream>

using namespace std;



class Node
{
public:
    Node *next;
    int data;
};


void insertLast(int data, Node *&head, Node *&last);

void insertAt(int data, int position, Node *&head, Node *&last)
{
    if(position < 0) {
        cout << "Negative position is invalid." << endl;
        return;
    }
    if (head == nullptr)
    {
        head = new Node();
        head->data = data;
        head->next = nullptr;
        last = head;
        return;
    }
    int currentPos = 0;


    if(position == 0) {
        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
        return;
    }

    Node *node = head;
    Node *prevNode = nullptr;
    do
    {
        if (currentPos == position)
        {
            Node *temp = new Node();
            temp->data = data;
            prevNode->next = temp;
            temp->next=node;
            return;
        }
        prevNode = node;
        node = node->next;
        if(node != nullptr) {
            currentPos++;

        }
    } while (node != nullptr);
    if((position - currentPos) > 1) {
    cout << "Position is far too large.";
    } else {
        cout << "POs" << currentPos << endl;
        insertLast(data, head, last);
    }


}

void insertLast(int data, Node *&head, Node *&last)
{

    if (head == nullptr)
    {
        head = new Node();
        head->data = data;
        head->next = nullptr;
        last = head;
        return;
    }

    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    last->next = temp;
    last = temp;
}

void removeFirst(Node *&head, Node *&last)
{
    if (head == nullptr)
    {
        cout << "Nothing to remove";
        return;
    }

    if (last == head)
    {
        delete head;
        head = nullptr;
        last = nullptr;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void removeLast(Node *&head, Node *&last)
{
    if (head == nullptr)
    {
        cout << "Nothing to remove";
        return;
    }

    if (last == head)
    {

        delete head;
        head = nullptr;
        last = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    delete last;
    last = temp;
    last->next = nullptr;
}

void showItems(Node *head)
{
    Node *temp = head;

    cout << endl<< "Linked List: ";
    if (head == nullptr)
    {
        cout << "empty";
    }
    do
    {
        cout << temp->data;
        temp = temp->next;
        if (temp != nullptr)
            cout << " -> ";
    } while (temp != nullptr);
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    Node *last = nullptr;


    cout << "Linked List is empty." << endl;
    bool loop = true;
    do
    {
        int action;
        cout << "\n1. Insert \n2. Delete \n0. Exit \n\nInput: ";
        cin >> action;
        switch (action)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            int pos;
            if(head != nullptr) {
                showItems(head);
                cout << "Enter position (0-index): ";
                cin >> pos;
                insertAt(data, pos,head, last);

            } else {
                insertLast(data,head,last);
            }
            showItems(head);
            break;
        case 2:
            break;
        case 0:
            loop = false;
            break;
        default:
            break;
        }

    } while (loop);

    return 0;
}
