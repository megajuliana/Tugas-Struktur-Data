// double linked list non circular:
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void travForward(Node *p);

int main(){
    Node *a =  NULL;    
    Node *b =  NULL;    
    Node *c =  NULL;
    
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
    

    return 0;
}

void travForward(Node *p)
{
    int i = 0;
    int terbesar = p->data;

    while (p != NULL){
        cout << "data ke " << i+1 << " : " << p->data << endl;
        
        if (p->data > terbesar){
            terbesar = p->data;
        }
        
        p = p->next;
        i++;
    }
    
    cout << "Terbesar adalah : " << terbesar << endl;
}


