// double linked list non circular:
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void tambahAkhir(Node*& head, int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->prev = temp; 
    }
}

void tambahAwal(Node*& head, int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = head;
    baru->prev = NULL;

    if (head != NULL) {
        head->prev = baru; 
    }

    head = baru;
}

void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void tampilkanBalik(Node* head) {
    if (head == NULL) return;

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int n, nilai;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nilai ke " << i+1 << ": ";
        cin >> nilai;
        tambahAkhir(head, nilai);
    }
    cout << endl;

    cout << "Masukkan data yang ditambahkan di awal: ";
    cin >> nilai;
    tambahAwal(head, nilai);
    cout << endl;

    cout << "Data setelah ditambah di awal (Forward): " << endl;
    tampilkan(head);

    cout << "Data (Backward): " << endl;
    tampilkanBalik(head);

    return 0;
}
