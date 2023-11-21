/*
     *** Adjacency Matrix ***

  optional<vector<T>> adjMatEq(vector<pair<IT, IT>> adj, vector<T> bs);

  Solves equation A x = b, where A is an adjacency matrix of size (m,n)

  arguments:
      adj .. Adjacency matrix, that is., every column should consist
             of a 1, and a -1, and the others should be zero.
      bs  .. A vector of size m.

  return value:
     If the equation does not have a solution, the return value is nullopt.
     Otherwise, it is a vector of size n, expressing a solution.

  note: 
     Usually there are two or more solutions, but it returns only one of them.
     Rows correspond vertices and columns corresponds edges.
     When edge p connects vertices i and j, A(i,p) = 1 and A(j,p) = -1.

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- adjMatrix.cc

template<typename T, typename IT> // IT is typically int or ll
optional<vector<T>> adjMatEq(vector<pair<IT, IT>> adj, vector<T> bs) {
  int m = adj.size(); // number of edges
  int n = bs.size();   // number of vertices
  vector<T> ret(m);

  using sta = tuple<int, int, bool>;
  auto nbr = vector(n, vector<sta>());
  for (int i = 0; i < m; i++) {
    auto [u, v] = adj[i];
    nbr[u].emplace_back(v, i, true);
    nbr[v].emplace_back(u, i, false);
  }
  vector<bool> visited(n);
  auto dfs = [&](auto rF, int v) -> T {
    if (visited[v]) return (T)0;
    visited[v] = true;
    T t = bs[v];
    for (auto [w, i, dir] : nbr[v]) {
      T tt = rF(rF, w);
      ret[i] = dir ? -tt : tt;
      t += tt;
    }
    // DLOGK(v, t);
    return t;
  };
  for (int v = 0; v < n; v++) {
    if (dfs(dfs, v) != (T)0) return nullopt;
  }
  return ret;
}


// @@ !! END ---- adjMatrix.cc
