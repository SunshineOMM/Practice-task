#include <iostream>
#include <stdlib.h>


using namespace std;

int DEFAULT_SIZE = 10;

int table(int n) {
	static int t[] = {
		98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219, 61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115, 90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10, 237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121, 123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55, 59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222, 197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186, 39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99, 154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254, 133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139, 189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44, 183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12, 221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166, 3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117, 238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110, 43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239
	};
	return t[abs(n)];
}

int HashFunction(const char* str)
{
	int h = 0;
	while (*str != 0) {
		h =table( h ^ *str);
		++str;
	}
	return h;
}


class HashTable {
public:
	struct Node {
		const char* _key;
		double _val;
		Node(const char* key,  const double val) : _key(key), _val(val) {}
	};
private:
	struct Data {
		Node* _data;
		bool _del;
		Data() : _data(nullptr), _del(false) {}
		Data(Node data) : _data(new Node(data)), _del(false) {}
	};

	Data* _arr;
	const int _size;// суммарное количество мест в хэш-таблице
	int _count;// количество элементов в хэш-таблице
	int(*_hash)(const char*);
public:
	HashTable() :_arr(new Data[DEFAULT_SIZE]()), _size(DEFAULT_SIZE), _count(0), _hash(HashFunction) {}
	HashTable(const HashTable&) = delete;
	HashTable& operator=(const HashTable&) = delete;
	~HashTable() {

		for (int i = 0; i < _size; ++i) {
			if (_arr[i]._data)
				delete _arr[i]._data;
		}
		delete[] _arr;
		_count = 0;
	}

	int GetSize()const {
		return _size;
	}

	bool Insert(const Node& n) {
		Data data = *new Data(*new Node(n._key, n._val));
		int ind = _hash(n._key) % 10; 
		while(_arr[ind]._data!=nullptr && _arr[ind]._del==false && ind<_size){
			++ind;
		}
		if (ind == _size) return false;
		if (_arr[ind]._del == true) delete _arr[ind]._data;
		this->_arr[ind] = data;
		return true;
	}

	bool IsContempt(const char* c)const {
		int ind = _hash(c) % 10;
		while (  ind < _size) {
			if (_arr[ind]._data && _arr[ind]._data->_key == c && _arr[ind]._del == false) return true;
			++ind;
		}
		return false;
	}

	Node* Find(const char* c)const {
		int ind = _hash(c) % 10;
		while (ind < _size) {
			if (_arr[ind]._data && _arr[ind]._data->_key == c && _arr[ind]._del == false) return (_arr+ind)->_data;
			++ind;
		}
		return nullptr;
	}

	bool Erase(const char* c) {
		if (!IsContempt(c)) return false;
		int ind = _hash(c) % 10;
		while (ind < _size) {
			if (_arr[ind]._data && _arr[ind]._data->_key == c && _arr[ind]._del == false) {
				_arr[ind]._del = true;
				return true;
			}
			++ind;
		}
	}
	void Print(ostream& out) {
		for (int i = 0; i < _size; ++i) {
			if (!_arr[i]._data) out << "NULL";
			else out<< _arr[i]._data->_key <<" : " << _arr[i]._data->_val;			
			out << endl;
		}
		out << "End of print" << endl << endl;
	}
};










void shmain() {


	HashTable ht;
	ht.Print(cout);

	HashTable::Node node1 = *new HashTable::Node("hello",0);
	HashTable::Node node2 = *new HashTable::Node("hlelo", 1);
	HashTable::Node node3 = *new HashTable::Node("holle",  2);
	HashTable::Node node4 = *new HashTable::Node("lehlo",  3);
	HashTable::Node node5 = *new HashTable::Node("lelho",  4);
	HashTable::Node node6 = *new HashTable::Node("o",  4);

	ht.Insert(node1);
	ht.Insert(node2);
	ht.Insert(node3);
	ht.Insert(node4);
	ht.Insert(node5);

	ht.Print(cout);

	cout << ht.IsContempt("hello")<<endl;
	cout << ht.IsContempt("o") << endl;

	cout << endl;
	cout << endl;

	cout<<ht.Find("hello") << endl;
	cout << ht.Find("o") << endl;








	/*HashTable<int>::Data d1 = *new HashTable<int>::Data();
	cout << d1._data << " " << d1._del<<endl;

	HashTable<int>::Data d2 = *new HashTable<int>::Data(5);
	cout << *d2._data << " " << d2._del << endl;*/
}