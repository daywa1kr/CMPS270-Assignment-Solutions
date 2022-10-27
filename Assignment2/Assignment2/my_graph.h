#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
private:
	std::unordered_map<int, std::vector<int>> adjList;

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

	static void main() {
		std::vector<int> start = { 0, 0, 0, 4, 4, 3 };
		std::vector<int> end = { 1, 2, 3, 3, 1, 1 };
		Graph g(start, end);

		g.print();
	}
};
