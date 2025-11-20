#include <iostream>
using namespace std;

int maxSize;
int topIndex = -1; 

bool isEmpty() {
    return topIndex == -1;
}

bool isFull() {
    return topIndex == maxSize - 1;
}

void push(int stack[]) {
    if (isFull()) {
        cout << "Stack penuh! Tidak dapat menambah data.\n";
    } else {
        int value;
        cout << "Masukkan nilai: ";
        cin >> value;
        topIndex++;
        stack[topIndex] = value;
        cout << "Data berhasil ditambahkan.\n";
    }
}

void pop(int stack[]) {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data untuk dihapus.\n";
    } else {
        cout << "Data yang di-pop: " << stack[topIndex] << endl;
        topIndex--;
    }
}

void peek(int stack[]) {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data di puncak.\n";
    } else {
        cout << "Elemen paling atas: " << stack[topIndex] << endl;
    }
}

void size() {
    cout << "Jumlah elemen dalam stack: " << (topIndex + 1) << endl;
}


int main() {
    cout << "Masukkan kapasitas maksimum stack: ";
    cin >> maxSize;

    int *stack = new int[maxSize];

    int pilihan;
    do {
        cout << "\n=== MENU STACK ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. IsEmpty\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            peek(stack);
            break;
        case 4:
            cout << (isEmpty() ? "Stack kosong.\n" : "Stack tidak kosong.\n");
            break;
        case 5:
            size();
            break;
        case 6:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    delete[] stack;
    return 0;
}
