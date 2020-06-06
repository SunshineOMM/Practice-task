#include<iostream>
#include<limits>
const auto INFINITY_INT= std::numeric_limits<int>::infinity();
using namespace std;
struct Node {
	int _info;
	Node* _left, * _right;
};
void KLPprint(Node* root) {
	if (!root) return;
	cout << root->_info;
	KLPprint(root->_left);
	KLPprint(root->_right);
}
void LPKprint(Node* root) {
	if (!root) return;
	LPKprint(root->_left);
	LPKprint(root->_right);
	cout << root->_info;
}

void LKPprint(Node* root) {
	if (!root) return;
	LKPprint(root->_left);
	cout << root->_info;
	LKPprint(root->_right);
}


int findMinNodeTree(Node* root, int min) {

	if (!root) return INFINITY_INT;
	int minl = findMinNodeTree(root->_left, min);
	if (minl < min) min = minl;
	int minr = findMinNodeTree(root->_right, min);
	if (minr < min) min = minr;

	if (root->_info < min) min = root->_info;
	return min;
}

int findMin(Node* root) {
	if (!root) return INFINITY_INT;
	int min =findMinNodeTree(root, root->_info);
	return min;
}

// Подсчёт среднего арифметического
void Average(Node* root, int& sum, int& count) {
	if (root->_left) Average(root->_left, sum, count);
	if(root->_right) Average(root->_right, sum, count);
	sum += root->_info;
	++count;
}

void __fmain() {
	Node* el1 = new Node;
	el1->_info = 1;

	Node* el2 = new Node;
	el2->_info = 2;

	Node* el3 = new Node;
	el3->_info = 3;

	Node* el4 = new Node;
	el4->_info = 4;

	Node* el5 = new Node;
	el5->_info = 5;

	el1->_left = el2;
	el1->_right = el5;
	
	el2->_left = el3;
	el2->_right = nullptr;

	el5->_right = el4;
	el5->_left = nullptr;

	el3->_right = nullptr;
	el3->_left = nullptr;

	el4->_right = nullptr;
	el4->_left = nullptr;

	int sum = 0;
	int count = 0;
	Average(el1,sum,count);
	cout << sum / count;
}