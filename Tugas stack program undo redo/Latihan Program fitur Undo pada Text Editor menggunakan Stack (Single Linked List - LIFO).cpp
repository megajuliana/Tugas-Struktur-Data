#include <iostream>
using namespace std;

// Stack with Single Linked List
// Fitur Undo
struct Node {
    string data;
    Node* next;
};

Node* top = NULL;

void push(string teks) {
    Node* baru = new Node;
    baru->data = teks;
    baru->next = top;
    top = baru;
}

void pop() {
    if (top != NULL) {
        Node* temp = top;
        cout << "Undo teks: " << temp->data << endl;
        top = top->next;
        delete temp;
    } else {
        cout << "Tidak ada data untuk di undo!\n";
    }
}

void tampil() {
    if (top == NULL) {
        cout << "Dokumen kosong.\n";
        return;
    }

    cout << "\n=== ISI DOKUMEN ===\n";
    Node* temp = top;
    int i = 1;

    while (temp != NULL) {
        cout << i++ << ". " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int pilih = 0;
    string teks;

    while (pilih != 4) {
        cout << "\n=== TEKS EDITOR ===\n";
        cout << "1. Ketik Teks\n";
        cout << "2. Undo\n";
        cout << "3. Tampilkan Dokumen\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan teks: ";
            getline(cin, teks);
            push(teks);
        }
        else if (pilih == 2) {
            pop();
        }
        else if (pilih == 3) {
            tampil();
        }
        else if (pilih == 4) {
            cout << "Keluar program \n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
