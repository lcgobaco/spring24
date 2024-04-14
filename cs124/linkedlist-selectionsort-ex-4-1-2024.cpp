// https://gist.github.com/muhammedeminoglu/b6e38c66d034374661e33fe191b846b0

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node* start = nullptr;
Node* last = nullptr;
Node* temp;

void swapNode(Node *x, Node *y);
Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void addLast(int y) {
    Node* node = createNode(y);
    if(start == nullptr) {
        start = node;
        last = node;
    }
    else {
        last->next = node;
        last = node;
    }
}

void printLinked() {
    temp = start;
    while(temp->next != nullptr)
    {
		cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void init(int size)
{
    int i, number;
    for( i = 0; i < size; i++ )
    {
        number = rand()%10000;
        addLast(number);
    }
}

void selectionLinked()
{
    Node* key;
    key = start;

    while(key != nullptr)
    {
        temp = key->next;
        while(temp != nullptr)
        {
            if(key->data > temp->data)
            {
                swapNode(key, temp);
            }
            temp = temp->next;
        }
        key = key->next;
    }
}

void swapNode(Node* x,Node* y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

int main()
{
    int choice;
    while( 1 == 1)  {
        cout << "\n How many numbers do you want to create ... ";
        cin >> choice;
        init(choice);
        selectionLinked();
        printLinked();
    }

}