#include <iostream>
using namespace std;

// single linked list:
struct Node {
    int data;
    Node* next;
};

void tambahNode ( Node*& head, int nilai ) {
    Node* baru = new Node();
    baru -> data = nilai;
    baru -> next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = baru;
    }
}

void tampilkan (Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int n, nilai;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << ": ";
        cin >> nilai;
        tambahNode (head, nilai);
    }
	cout << endl;
	
    cout << "Masukkan nilai yang ditambahkan di akhir: ";
    cin >> nilai;
    tambahNode (head, nilai);
    cout << endl;

    cout << "Data setelah ditambah di akhir: " << endl;
    tampilkan (head);

    return 0;
}


