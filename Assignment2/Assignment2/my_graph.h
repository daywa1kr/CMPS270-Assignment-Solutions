#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
/*
	a graph class with integer vertices
*/
class Graph {
private:
	std::unordered_map<int, std::vector<int>> adjList;
	std::vector<int> visited;
	std::vector<int> parent;
	int start, end;

public:
	/*
		requires: a refrence to a vector start of ints containing vertices that have outgoing edges 
			      and a reference to a vector containing the vertices each vertex in start goes to
				  e.g. start: 0 0 0 4 4 3
					   end:   1 2 3 3 1 1 

		effects: creates an adjacency list using an unordered map that maps ints (each vertex) to it's outgoing neighbours in a vector
		assumes: we're dealing with connected graphs, assumes the vertices are marked with non ngeative ints

		tests:
			tested with cyclic and acyclic graphs -> valid, graph created
			start and end vectors with uneven and even sizes -> invalid, adjList is not filled and user is promped
	*/
	Graph(const std::vector<int>& starts, const std::vector<int>& ends) {
		if (starts.size() == ends.size()) {
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
		else
			std::cout << "Please make sure all the vertices in the graph are connected\n";
	}
	/*
		effects: clears the map and the vectors upon the destruction of the object
	*/
	~Graph() {
		for (auto& i : adjList) {
			i.second.clear();
		}
		adjList.clear();
	}
	/*
		effects: returns number of adjacent nodes of the vertex with nodeID

		tests:
			valid numbers between 0 and adjList.size()
			negative and out of bound numbers -> returns -1
	*/
	int numOutgoing(const int nodeID) {
		if (nodeID >= 0 && nodeID < adjList.size()) {
			return adjList[nodeID].size();
		}
		std::cout << "invalid ID\n";
		return -1;
	}
	/*
		effects: returns all adjacent nodes of the vertex with nodeID in a vector
		tests:
			valid numbers between 0 and adjList.size()
			negative and out of bound numbers -> propmts the user
	*/
	std::vector<int>& adjacent(const int nodeID) {
		std::vector<int> tmp;
		if (nodeID >= 0 && nodeID < adjList.size()) {
			tmp=adjList[nodeID];
		}
		else {
			std::cout << "invalid ID\n";
		}
		return tmp;
	}
	/*
		effects: prints the adjecancy list of the graph
	*/
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
	/*
		effects: checks if the graph contains cycles. if so prints out the vertices that make up the cycle
		tests: acyclic and cyclic graphs and gives the right output
	*/
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
	/*
		main function to test graph class in main.cpp
	*/
	static void main() {
		std::vector<int> start = { 0, 0, 0, 4, 4, 3 };
		std::vector<int> end = { 1, 2, 3, 3, 1, 1 };
		Graph g(start, end);

		g.print();

		std::cout << "num of outgoing for 1: " << g.numOutgoing(1)<<'\n';

		std::vector<int> adj = g.adjacent(-1);
		for (int i = 0; i < adj.size(); i++) {
			std::cout << adj[i] << ' ';
		}
		std::cout << '\n';

		g.hasCycle();

		std::vector<int> start2 = { 0, 1, 2 };
		std::vector<int> end2 = { 1, 2, 0 };
		Graph g2(start2, end2);

		g2.print();

		g2.hasCycle();

		std::cout << '\n';

		std::vector<int> start3 = { 0, 1, 2, 3 };
		std::vector<int> end3 = { 1, 2, 0 };
		Graph g3(start3, end3);
	}

private:
	/*
		helper function for hasCycle()

		requires: an int representing a vertex v contained in a graph
		effects: performs dfs starting from the vertex v
	*/
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
