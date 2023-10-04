#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;
};

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
    cout << "Linked List: ";
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
        cout << "1. Insert \n2. Delete \n3. Show All \n0. Exit \n";
        cin >> action;
        switch (action)
        {
        case 1:
            int data;
            cout << "Enteasdfr data: ";
            cin >> data;
            insertLast(data, head, last);
            showItems(head);
            break;
        case 2:
            break;
        case 3:
            showItems(head);
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
