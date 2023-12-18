#include <iostream>

class Node
{ 
    public:
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *head, *tail;
    public:
        LinkedList();
        void createNode(int value);
        void display();
        void insertStart(int value);
        void insertPosition(int pos, int value);
        void deleteFirst();
        void deleteLast();
        void deletePosition(int pos);
        ~LinkedList();
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

void LinkedList::createNode(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::display()
{
    Node* temp = new Node;
    temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LinkedList::insertStart(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

void LinkedList::insertPosition(int pos, int value)
{
    Node* previous = new Node;
    Node* current = new Node;
    Node* temp = new Node;
    current = head;
    for (int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    temp->data = value;
    previous->next = temp;
    temp->next = current;
}

void LinkedList::deleteFirst()
{
    Node* temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteLast()
{
    Node* current = new Node;
    Node* previous = new Node;
    current = head;
    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = nullptr;
    delete current;
}

void LinkedList::deletePosition(int pos)
{
    Node* current = new Node;
    Node* previous = new Node;
    current = head;
    for (int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

LinkedList::~LinkedList()
{
    Node* temp = new Node;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    } 
}

int main()
{
    LinkedList list;
    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);
    list.createNode(5);
    list.display();
    list.insertStart(0);
    list.display();
    list.insertPosition(3, 2);
    list.display();
    list.deleteFirst();
    list.display();
    list.deleteLast();
    list.display();
    list.deletePosition(3);
    list.display();
    
    return 0;
}

