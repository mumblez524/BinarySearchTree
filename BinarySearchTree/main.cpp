#include "BSTree.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	BSTree<int> tree;
	int num, value, choice;
	cout << "1. Create my own tree. \n2. Create tree using halfmillion.txt file.\n";
	cout << "Choice (Number only): ";
	cin >> choice;
	cout << endl;
	if (choice == 1) {
		cout << "How many values do you wish to insert? ";
		cin >> num;
		for (int i = 1; i <= num; i++) {
			cout << i << ": ";
			cin >> value;
			tree.insert(value);
		}
		cout << endl;
		cout << "Preorder	: ";
		tree.preorder();
		cout << endl;
		cout << "Postorder	: ";
		tree.postorder();
		cout << endl;
		cout << "Inorder		: ";
		tree.inorder();
		cout << endl;
	}
	else if (choice == 2) {
		cout << "Creating tree from halfmillion.txt file.";
		ifstream input;
		input.open("halfmillion.txt");
		if (!input) {
			cout << "Error" << endl;
			system("PAUSE");
			return 0;
		}
		while (!input.eof()) {
			input >> value;
			tree.insert(value);
		}
		cout << endl;
		cout << "Preorder	: ";
		tree.preorder();
		cout << endl;
		cout << "Postorder	: ";
		tree.postorder();
		cout << endl;
		cout << "Inorder		: ";
		tree.inorder();
	}
	system("PAUSE");
	return 0;
}