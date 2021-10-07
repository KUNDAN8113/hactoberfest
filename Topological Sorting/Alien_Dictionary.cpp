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


	unordered_set<char> s;

	map<char , unordered_set<char>> adjList;

	int n;
	cin >> n;

	vector<string> words(n);

	for (int i = 0 ; i < n ; i++) {
		cin >> words[i];

		for (auto c : words[i]) {
			s.insert(c);
		}
		cout << words[i] << " ";
	}

	cout << endl;

	for (int i = 0 ; i < n - 1 ; i++) {

		for (int j = 0  ; j < min(words[i].length() , words[i + 1].length()) ; j++) {

			if (words[i][j] != words[i + 1][j]) {
				cout << words[i][j] << " " << words[i + 1][j] << endl;
				adjList[words[i][j]].insert(words[i + 1][j]);

				break;
			}

		}
	}

	for (auto i : adjList) {
		auto node = i.first;
		cout << node << " --> ";
		for (auto nbr : i.second) {
			cout << nbr << " ";
		}
		cout << endl;
	}

	map<char , int> indegree;

	for (auto row : adjList) {
		char node = row.first;
		for (auto nbr : adjList[node]) {
			indegree[nbr]++;
		}
	}

	queue<char> q;

	for (auto c : s) {
		cout << c << "  " << indegree[c] << endl;
		if (indegree[c] == 0) {
			q.push(c);
		}
	}

	while (!q.empty()) {
		char c = q.front();
		cout << c;
		q.pop();

		for (char nbr : adjList[c]) {
			indegree[nbr]--;
			if (indegree[nbr] == 0) {
				q.push(nbr);
			}
		}
	}

	return 0;
}