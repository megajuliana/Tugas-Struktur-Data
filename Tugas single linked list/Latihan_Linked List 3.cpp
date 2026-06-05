#include <iostream>
using namespace std;

// single linked list:
struct Node {
    int data;
    Node* next;
};

void trav(struct Node *p);

int main(){
    Node *a =  NULL;    
    Node *b =  NULL;    
    Node *c =  NULL;
    
    a = new Node;
    b = new Node;
    c = new Node;
    
    a->data = 10;
    a->next = b;
    
    b->data = 20;
    b->next = c;
    
    c->data = 30;
    c->next = NULL;
    
    trav(a);
}

void trav(struct Node *p)
{
    int i = 0;
    int total = 0; 
    
    while (p != NULL){
        cout << "data ke " << i+1 << " : ";
        cout << p->data << endl;
        
        total += p->data; 
        
        p = p->next;
        i++;
    }
    
    cout << "Total nilai adalah : " << total << endl;
}


