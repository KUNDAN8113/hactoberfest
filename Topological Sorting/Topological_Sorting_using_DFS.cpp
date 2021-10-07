#include<iostream>
#include<map>
#include<list>
#include<vector>

using namespace std;

// template<typename T>

// class Graph {
// public:

// 	map<T , list<T>> adjList;

// 	void addEdge(T u , T v , bool bidir = true) {
// 		adjList[u].push_back(v);
// 		if (bidir == true)
// 			adjList[v].push_back(u);
// 	}

// 	void print() {
// 		for (auto row : adjList) {
// 			T node = row.first;
// 			cout << node << " -> ";

// 			for (auto neighbour : adjList[node]) {
// 				cout << neighbour << " , ";
// 			}
// 			cout << endl;
// 		}
// 	}

// 	void helper(T node , map<int , bool> &visited , list<int> &ordering) {
// 		visited[node] = true;

// 		for (auto neighbour : adjList[node]) {
// 			if (!visited[neighbour]) {
// 				helper(neighbour , visited , ordering);
// 			}
// 		}

// 		ordering.push_front(node);
// 	}

// 	void DFS_Topological() {
// 		map<T , bool> visited;
// 		list<T> ordering;

// 		for (auto row : adjList) {
// 			T node = row.first;
// 			if (!visited[node]) {
// 				helper(node , visited , ordering);
// 			}
// 		}

// 		for (auto i : ordering)
// 			cout << " -> " << i;
// 	}

// };




void dfs(vector<vector<int>> &adjList , int node , vector<bool> &visited , list<int> &ordering) {
	visited[node] = true;

	for (int neighbour : adjList[node]) {
		if (!visited[neighbour]) {
			dfs(adjList , neighbour , visited , ordering);
		}
	}

	ordering.push_front(node);
}

void topologicalSorting(vector<vector<int>> &adjList) {
	int v = adjList.size();

	vector<bool> visited(v + 1);
	list<int> ordering;

	for (int i = 0 ; i < v ; i++) {
		if (!visited[i])
			dfs(adjList , i , visited , ordering);
	}

	for (auto val : ordering) {
		cout << val << " ";
	}
}



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

	// g.DFS_Topological();













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

	for (int i = 0 ; i < v ; i++) {
		for (int nbr : adjList[i]) {
			cout << nbr << " ";
		}
		cout << endl;
	}

	topologicalSorting(adjList);




	return 0;
}