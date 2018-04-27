#include "bits_stdc.h"


int largestDistanceTwoNodesUtil(vector<vector<int>> &graph, int vertex, int *height) {

	if (graph[vertex].size() == 0) {
		*height = 1;
		return 0;
	}

	int maxD = 0;

	int maxH = 0;
	int maxH2 = 0;
	for (int i = 0; i < graph[vertex].size(); i++) {
		int h;
		maxD = max(maxD, largestDistanceTwoNodesUtil(graph, graph[vertex][i], &h));
		if (h > maxH) {
			maxH2 = maxH;
			maxH = h;
		}
		else if (maxH2 < h) {
			maxH2 = h;
		}
	}
	*height = maxH + 1;

	return max(maxH + maxH2, maxD);
}


int largestDistanceTwoNodes(vector<int> input) {

	int v = input.size();
	vector<vector<int>> graph(v);

	for (int i = 0; i< v; i++) {
		if (input[i] != -1)
			graph[input[i]].push_back(i);
	}

	int h;
	return largestDistanceTwoNodesUtil(graph, 0, &h);
}

int main_int42() {

	vector<int> in = { -1, 0, 0, 0, 3 };
	cout << largestDistanceTwoNodes(in);

	return 0;
}