#include<iostream>
using namespace std;

int COUNTER = 0;

///������ 1) �������� ���������, ��������������� ��� ��������� n-��������� ����� � ������� ��������� � ���������� k(k<=10). 
void n_bit_numbers(int elem, int n, int k, int* mas) { //elem -����� ������� ������� �������� (�� ����� ������� � 0)
	if (elem == n) { // �.�. ��� ��� ����� ��������� ������� ������� � ����� ��������
		for (int j = 0; j < n; j++) {
			cout << mas[j];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < k; i++)
	{
		mas[elem] = i;
		n_bit_numbers(elem + 1, n, k, mas);
	}
}

//������  2)  �����  ��  ����  ���������  ���������  �  ����  �� - ��������  ������  ��������� �������(��������, �abcd123�).
//�������� ���������, ��������������� ��� ��������� ������ ����� n, ������������ �� �������� ����� ��������.
void placement_from_n_to_k(int elem, int* mas, char* arr, int size, int len) {
	if (elem == len) { // �.�. ��� ��� ����� ��������� ������� ������� � ����� ��������
		for (int j = 0; j < len; j++) {
			cout << arr[mas[j]];
			
		}
		++COUNTER;
		cout << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		mas[elem] = i;
		placement_from_n_to_k(elem + 1, mas, arr,  size, len);
	}
}

//������ 3) ������ ���������� ������ ����� �������, ����� ��������� ������������� ��� ��������� ������ �� ����� ��� �������� �����.
void placement_from_n_to_k_to_a_given_length(int elem, int* mas, char* arr, int size, int len) {
	if (elem <= len) { // �.�. ��� ��� ����� ��������� ������� ������� � ����� ��������
		for (int j = 0; j < elem; j++) {
			cout << arr[mas[j]];
		}
		++COUNTER;
		cout << endl;
		if (elem == len)return;
	
	}
	for (int i = 0; i < size; i++)
	{
		mas[elem] = i;
		placement_from_n_to_k_to_a_given_length(elem + 1, mas, arr, size, len);
	}
}


//������ 4)  �������� ��������� ������������ � ������������������ �������.
void Swap(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

void Print(int* a, int n)  // ����� ������������
{
	static int num = 1; // ����� ������������
	cout.width(3); // ������ ���� ������ ������ ������������
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

bool NextSet(int* a, int n)
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false; // ������ ������������ ���
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	Swap(a, j, k);
	int l = j + 1, r = n - 1; // ��������� ���������� ����� ������������������
	while (l < r)
		Swap(a, l++, r--);
	return true;
}

//������ 5)  �������� ��������� ������������ .
void permutations(char* arr,int size, int pos = 0)
{
	if (pos >= size)
	{
		for (int j = 0; j < size; j++) {
			cout << arr[j];
		}
		cout << '\n';
		COUNTER++;
		return;
	}
	else
	{
		for (int i = pos; i < size; ++i)
		{
			std::swap(arr[i], arr[pos]);
			permutations(arr,size, pos + 1);
			std::swap(arr[i], arr[pos]);
		}
	}
}

void ______________________________main()
{
	////# 1
	//cout << "write a k" << endl;
	//int k;
	//cin >> k;

	//cout << "write a n" << endl;
	//int n;
	//cin >> n;
	//int* mas = new int[n];

	//n_bit_numbers(0, n, k, mas);

	////#2	
	//cout << "write a len" << endl;
	//int len;
	//cin >> len;
	//int* mas = new int[len];
	//char* arr = new char[4]{ 'f','5','4','j' };

	//placement_from_n_to_k(0, mas,arr,4, len);


	////#3	
	//cout << "write a len" << endl;
	//int len;
	//cin >> len;
	//int* mas = new int[len];
	//char* arr = new char[4]{ 'f','5','4','j' };

	//placement_from_n_to_k_to_a_given_length(0, mas, arr, 4, len);



	////#4
	//int n, * a;
	//cout << "N = ";
	//cin >> n;
	//a = new int[n];
	//for (int i = 0; i < n; i++)
	//	a[i] = i + 1;
	//Print(a, n);
	//while (NextSet(a, n))
	//	Print(a, n);

	//#5
	char* arr = new char[4]{ 'f','5','4','j' };
	permutations(arr, 4);




	cout << COUNTER;

}