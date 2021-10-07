#include<iostream>
#include<queue>
#include<map>
#include<list>

using namespace std;

template<typename T>

class Graph {
public:

	map<T , list<T>> adjList;

	void addEdge(T u , T v , bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir == true)
			adjList[v].push_back(u);
	}

	void print() {
		for (auto row : adjList) {
			T node = row.first;
			cout << node << " -> ";

			for (auto neighbour : adjList[node]) {
				cout << neighbour << " , ";
			}
			cout << endl;
		}
	}

	int SumOfDependencies() {
		int ans = 0;

		for (auto row : adjList) {
			int node = row.first;
			for (auto neighbour : adjList[node]) {
				ans++;
			}
		}

		return ans;
	}


};





int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	int t;
	cin >> t;
	while (t--) {


		Graph<int> g;

		int n , e;
		cin >> n >> e;

		while (e--) {
			int u , v;
			cin >> u >> v;

			g.addEdge(u , v , false);
		}



		cout << g.SumOfDependencies() << endl;

	}







	return 0;
}