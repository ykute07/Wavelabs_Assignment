#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& cables) {
    vector<unordered_set<int>> graph(n);
    for (auto& cable: cables) {
        graph[cable[0]].insert(cable[1]);
        graph[cable[1]].insert(cable[0]);
    }
    int maximal = 0;
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int network_rank = graph[i].size() + graph[j].size();
            if (graph[j].count(i)) {
                --network_rank;
            }
            maximal = max(maximal, network_rank);
        }
    }
    return maximal;
}

int main() {
    int n = 4;
    vector<vector<int>> cables = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};

    int answer = maximalNetworkRank(n, cables);

    cout << answer << endl;

    return 0;
}
