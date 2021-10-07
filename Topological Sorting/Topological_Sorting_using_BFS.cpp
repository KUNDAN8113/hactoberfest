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

	void BFS_Topological() {
		queue<T> q;
		map<T , int> inDegree;

		for (auto row : adjList) {
			T node = row.first;
			for (auto neighbour : adjList[node]) {
				inDegree[neighbour]++;
			}
		}

		for (auto i : inDegree) {
			cout << i.first << " -> " << i.second;
			cout << endl;
		}

		for (auto i : adjList) {
			if (inDegree[i.first] == 0)
				q.push(i.first);
		}

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << " <- " << node ;

			for (auto neighbour : adjList[node]) {
				inDegree[neighbour]--;
				if (inDegree[neighbour] == 0)
					q.push(neighbour);
			}
		}
	}

};





int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif


	// Graph<int> g;

	// g.addEdge(0 , 1 , false);
	// g.addEdge(0 , 4 , false);
	// g.addEdge(1 , 2 , false);
	// g.addEdge(2 , 4 , false);
	// g.addEdge(2 , 3 , false);
	// g.addEdge(4 , 3 , false);
	// g.addEdge(3 , 5 , false);


	// g.print();

	// cout << endl;

	// g.BFS_Topological();



	int v;
	cin >> v;

	vector<vector<int>> adjList(v);

	int e;
	cin >> e;

	while (e--) {
		int u , v;
		cin >> u >> v;

		adjList[u].push_back(v);
	}

	vector<int> inDegree(v);
	vector<bool> visited(v);

	for (int i = 0 ; i < v ; i++) {
		for (int neighbour : adjList[i]) {
			inDegree[neighbour]++;
		}
	}

	queue<int> q;

	for (int i = 0 ; i < v ; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			visited[i] = true;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";

		for (int neighbour : adjList[node]) {
			inDegree[neighbour]--;
			if (inDegree[neighbour] == 0) {
				q.push(neighbour);
			}
		}
	}

	return 0;
}