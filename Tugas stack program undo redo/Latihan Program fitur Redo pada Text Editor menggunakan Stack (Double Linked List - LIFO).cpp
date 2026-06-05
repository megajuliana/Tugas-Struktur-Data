#include <iostream>
using namespace std;

// Stack with Double Linked List
// Fitur Redo
struct Node {
    string data;
    Node* next;
    Node* prev;
};

Node* top = NULL;
Node* redoTop = NULL;

void push(string teks) {
    Node* baru = new Node;
    baru->data = teks;
    baru->next = top;
    baru->prev = NULL;

    if (top != NULL)
        top->prev = baru;

    top = baru;

    while (redoTop != NULL) {
        Node* temp = redoTop;
        redoTop = redoTop->next;
        delete temp;
    }
}

void undo() {
    if (top != NULL) {
        Node* temp = top;
        cout << "Undo teks: " << temp->data << endl;

        top = top->next;
        if (top != NULL)
            top->prev = NULL;

        temp->next = redoTop;
        temp->prev = NULL;

        if (redoTop != NULL)
            redoTop->prev = temp;

        redoTop = temp;
    } else {
        cout << "Tidak ada data untuk di undo!\n";
    }
}

void redo() {
    if (redoTop != NULL) {
        Node* temp = redoTop;
        cout << "Redo teks: " << temp->data << endl;

        redoTop = redoTop->next;
        if (redoTop != NULL)
            redoTop->prev = NULL;

        temp->next = top;
        temp->prev = NULL;

        if (top != NULL)
            top->prev = temp;

        top = temp;
    } else {
        cout << "Tidak ada data untuk redo!\n";
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

    while (pilih != 5) {
        cout << "\n=== TEKS EDITOR ===\n";
        cout << "1. Ketik Teks\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Tampilkan Dokumen\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan teks: ";
            getline(cin, teks);
            push(teks);
        }
        else if (pilih == 2) {
            undo();
        }
        else if (pilih == 3) {
            redo();
        }
        else if (pilih == 4) {
            tampil();
        }
        else if (pilih == 5) {
            cout << "Keluar program\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
