#include <iostream>
#define MAX 100

using namespace std;

struct Stack {
	int top, data[MAX];
} Tumpukan;

void init() {
	Tumpukan.top = -1;
}

bool isEmpty() {
	return Tumpukan.top == -1;
}

bool isFull() {
	return Tumpukan.top == MAX - 1;
}

void push() {
	if (isFull()) {
		cout << endl << "Tumpukan penuh" << endl;
	} else {
		Tumpukan.top++;
		cout << endl << "Masukkan data: ";
		cin >> Tumpukan.data[Tumpukan.top];
		cout << "Data " << Tumpukan.data[Tumpukan.top] << " masuk ke stack" << endl;
	}
}

void pop() {
	if (isEmpty()) {
		cout << endl << "Data kosong" << endl << endl;
	} else {
		cout << endl << "Data " << Tumpukan.data[Tumpukan.top] << " sudah terambil" << endl;
		Tumpukan.top--;
	}
}

void printStack() {
	if (isEmpty()) {
		cout << "Tumpukan kosong";
	} else {
		cout << endl << "Tumpukan: ";
		for (int i = 0; i <= Tumpukan.top; i++) {
			cout << Tumpukan.data[i] << ", ";
		}
	}
}

int main() {
	int pilihan, data;
	
	init();
	do {
		printStack();
		cout << endl << "1. Input (Push)" << endl
					 << "2. Hapus (Pop)" << endl
					 << "3. Keluar" << endl
					 << "Masukkan pilihan: ";
		cin >> pilihan;
		switch (pilihan) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			default:
				cout << "Pilihan tidak tersedia" << endl;
		}
	} while (pilihan != 3);
	
	return 0;
}
