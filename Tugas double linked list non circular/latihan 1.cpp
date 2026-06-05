// double linked list non circular:
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void travForward(Node *p);
void travBackward(Node *p);

int main(){
    Node *a = NULL;    
    Node *b = NULL;    
    Node *c = NULL;

    a = new Node;
    b = new Node;
    c = new Node;

    a->data = 10;
    b->data = 20;
    c->data = 30;

    a->next = b;
    b->next = c;
    c->next = NULL;

    a->prev = NULL;
    b->prev = a;
    c->prev = b;

    cout << "Traversal Forward\n";
    travForward(a);

    cout << "\nTraversal Backward\n";
    travBackward(c);

    return 0;
}

void travForward(Node *p)
{
    int i = 0;
    while (p != NULL){
        cout << "data ke " << i+1 << " : " << p->data << endl;
        p = p->next;
        i++;
    }
    cout << "Jumlah data : " << i << endl;
}

void travBackward(Node *p)
{
    int i = 0;
    while (p != NULL){
        cout << "data ke " << i+1 << " : " << p->data << endl;
        p = p->prev;
        i++;
    }
    cout << "Jumlah data : " << i << endl;
}
