// credit for cen decomp: usaco.guide

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> subsize(n);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // lambda functions didnd't support default parameters value :(

  function<int(int, int)> getter = [&](int node, int parent) {
    subsize[node] = 1;
    for (auto u : adj[node]) {
      if (u == parent)
        continue;
      subsize[node] += getter(u, node);
    }
    return subsize[node];
  };

  function<int(int, int)> centroid = [&](int node, int parent) {
    for (auto u : adj[node]) {

      if (u == parent)
        continue;
      if (subsize[u] * 2 > n) {
        return centroid(u, node);
      }
    }
    return node;
  };
  getter(0, -1);
  cout << centroid(0, -1) + 1 << endl;
  return 0;
}
