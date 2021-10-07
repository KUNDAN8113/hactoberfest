#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	int n;
	cin >> n;

	vector<vector<int>> adjList(n + 1);
	vector<int> indegree(n + 1);

	int e;
	cin >> e;

	while (e--) {
		int u , v;
		cin >> u >> v;

		adjList[u].push_back(v);
		indegree[v]++;
	}

	queue<int> q;
	for (int i = 0 ; i <= n ; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ans(n + 1);

	int time = 1;
	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int node = q.front();
			q.pop();

			ans[node] = time;

			for (int nbr : adjList[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
		time++;
	}

	for (auto i : ans) {
		cout << i << " ";
	}



	return 0;
}

// 7
// 7
// 1 2
// 2 3
// 2 4
// 2 5
// 3 6
// 4 6
// 5 7