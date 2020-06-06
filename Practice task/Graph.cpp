#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

class graph {
public:
	map<char, map<char, double>> _map;


	graph() :_map() {}

	void AddVertex(char vertex) {
		_map.insert({ vertex,map<char,double>() });
	}
	void AddEdge(char srcV, char dstV, double way) {
		_map[srcV][dstV] = way;
	}

	size_t GetSize() {
		return _map.size();
	}

	void Print(ostream& out) {
		for (auto& srcV : _map) {
			out << srcV.first << " :"<<endl;
			char V = srcV.first;
			for (auto& dstV : _map[V]) {
				out << "\t"<<dstV.first << " :" << dstV.second << endl;
			}
			out << endl;
			out << endl;
			out << endl;
		}
	}
};

void DeepRecursiveSearch(graph& g, map<char, int>& visited, char srcV, vector<char>& res) {
	visited[srcV] = 1;
	for (auto& dst : g._map[srcV]) {
		if (visited[dst.first] == 0) {
			DeepRecursiveSearch(g, visited, dst.first, res);			
		}
		
	}
	if (visited[srcV] != 2) {
		visited[srcV] = 2;
		res.push_back(srcV);
	}
}

vector<char> TopologicalSort(graph& g) {
	map<char,int> visited;
	vector<char> res;
	for (auto& it : g._map) {
		visited.insert({ it.first,0 });
	}

	for (auto& it : g._map) {
		if (visited[it.first]!=2) {
			DeepRecursiveSearch(g, visited, it.first, res);// (*g._map.begin()).first
		}
	}
	reverse(res.begin(), res.end());
	return res;
}



void ___m365ain() {
	graph g;

	g.AddVertex('a');
	g.AddVertex('b');
	g.AddVertex('c');
	g.AddVertex('d');
	g.Print(cout);

	cout << endl;
	cout << endl;
	cout << endl;

	//g.AddEdge('a', 'b', 3);
	//g.AddEdge('a', 'c', 2);
	g.AddEdge('c', 'b', 4);
	g.AddEdge('c', 'd', 4);
	g.AddEdge('a', 'd', 3);
	//g.AddEdge('b', 'd', 4);
	g.AddEdge('b', 'a', 7);
	//g.AddEdge('d', 'a', 1);
	g.Print(cout);

	vector<char> res =TopologicalSort(g);
	for (auto& it : res) {
		cout << it;
	}


}