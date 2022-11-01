#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>

class Graph {
private:
	std::unordered_map<int, std::vector<int>> adjList;
	std::vector<int> visited;
	std::vector<int> parent;
	int start, end;

public:
	Graph(const std::vector<int>& starts, const std::vector<int>& ends) {
		for (int i = 0; i < starts.size(); i++) {
			if (adjList.find(starts[i]) == adjList.end()) {
				std::vector<int> tmp;
				tmp.push_back(ends[i]);
				adjList[starts[i]] = tmp;
			}
			else {
				adjList[starts[i]].push_back(ends[i]);
			}
			if (adjList.find(ends[i]) == adjList.end()) {
				std::vector<int> tmp;
				adjList[ends[i]] = tmp;
			}
		}
	}

	~Graph() {
		adjList.clear();
	}

	int numOutgoing(const int nodeID) {
		return adjList[nodeID].size();
	}

	std::vector<int>& adjacent(const int nodeID) {
		return adjList[nodeID];
	}

	void print() {
		for (auto& i : adjList) {
			std::cout << i.first << " -> ";
			for (int j = 0; j < i.second.size(); j++) {
				std::cout << i.second[j] << " ";
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	void hasCycle() {
		visited.assign(adjList.size(), 0);
		parent.assign(adjList.size(), -1);
		start = -1;

		for (int v = 0; v < adjList.size(); v++) {
			if (visited[v] == 0 && dfs(v))
				break;
		}

		if (start == -1) {
			std::cout << "The graph does not contain any cycles.\n";
		}
		else {
			std::vector<int> cycle;
			cycle.push_back(start);
			for (int v = end; v != start; v = parent[v])
				cycle.push_back(v);
			cycle.push_back(start);
			reverse(cycle.begin(), cycle.end());

			std::cout << "Cycle: ";
			for (int v : cycle)
				std::cout << v << " -> ";
		}
	}

	static void main() {
		std::vector<int> start = { 0, 0, 0, 4, 4, 3 };
		std::vector<int> end = { 1, 2, 3, 3, 1, 1 };
		Graph g(start, end);

		g.print();

		g.hasCycle();

		std::vector<int> start2 = { 0, 1, 2 };
		std::vector<int> end2 = { 1, 2, 0 };
		Graph g2(start2, end2);

		g2.print();

		g2.hasCycle();
	}

private:

	bool dfs(int v) {
		visited[v] = 1;
		for (int u : adjList[v]) {
			if (visited[u] == 0) {
				parent[u] = v;
				if (dfs(u))
					return true;
			}
			else if (visited[u] == 1) {
				end = v;
				start = u;
				return true;
			}
		}
		visited[v] = 2;
		return false;
	}
};
