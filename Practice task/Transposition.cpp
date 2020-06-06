#include<iostream>
using namespace std;

int COUNTER = 0;

///Задача 1) Напишите процедуру, распечатывающую все возможные n-разрядные числа в системе счисления с основанием k(k<=10). 
void n_bit_numbers(int elem, int n, int k, int* mas) { //elem -какой элемент выборки подается (по счету начиная с 0)
	if (elem == n) { // т.е. уже был подан последний элемент выборки и нужно печатать
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

//Задача  2)  Пусть  на  вход  процедуры  поступает  в  виде  си - подобной  строки  некоторый алфавит(например, «abcd123»).
//Напишите процедуру, распечатывающую все возможные строки длины n, составленные из символов этого алфавита.
void placement_from_n_to_k(int elem, int* mas, char* arr, int size, int len) {
	if (elem == len) { // т.е. уже был подан последний элемент выборки и нужно печатать
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

//Задача 3) Решите предыдущую задачу таким образом, чтобы процедура распечатывала все возможные строки не более чем заданной длины.
void placement_from_n_to_k_to_a_given_length(int elem, int* mas, char* arr, int size, int len) {
	if (elem <= len) { // т.е. уже был подан последний элемент выборки и нужно печатать
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


//Задача 4)  Алгоритм генерации перестановок в лексикографическом порядке.
void Swap(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

void Print(int* a, int n)  // вывод перестановки
{
	static int num = 1; // номер перестановки
	cout.width(3); // ширина поля вывода номера перестановки
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
		return false; // больше перестановок нет
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	Swap(a, j, k);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r)
		Swap(a, l++, r--);
	return true;
}

//Задача 5)  Алгоритм генерации перестановок .
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