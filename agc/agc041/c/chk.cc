#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  int N = stoi(string(argv[1]));
  vector<vector<char>> B(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    if ((int)s.size() != N) {
      cerr << "Line " << i << ": length mismatch" << endl;
      exit(1);
    }
    for (int j = 0; j < N; j++) {
      char c = s.at(i);
      if (!(c == '.' || ('a' <= c && c <= 'z'))) {
	cerr << "(" << i << ", " << j << "): invalid char" << endl;
	exit(1);
      }
      B.at(i).at(j) = s.at(j);
    }
  }

  const vector<pair<int, int>> dir({{1,0}, {-1,0}, {0,1}, {0,-1}});
  auto sanity = [&](int i, int j) -> void {
    int c = B.at(i).at(j);
    int found = false;
    for (auto p : dir) {
      int ii = i + p.first;
      int jj = j + p.second;
      // cerr << "**** " << ii << ", " << jj << endl;
      if (0 <= ii && ii < N && 0 <= jj && jj < N && B.at(ii).at(jj) == c) {
	if (found) {
	  cerr << "(" << i << ", " << j << "): #piece >= 3" << endl;
	  exit(1);
	}
	found = true;
      }
    }
    if (!found) {
      cerr << "(" << i << ", " << j << "): #piece == 1" << endl;
      exit(1);
    }
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (B.at(i).at(j) == '.') continue;
      sanity(i, j);
    }
  }

  int qual = -1;
  auto qCheck = [&](int i0, int j0, int di, int dj) -> void {
    int count = 0;
    int i = i0, j = j0;
    for (int t = 0; t < N; t++) {
      char prev = t == 0 ? '.' : B.at(i - di).at(j - dj);
      char cur = B.at(i).at(j);
      if (cur != '.' && cur != prev) count++;
      i += di, j += dj;
    }
    if (qual == -1) {
      qual = count;
    }else if (qual != count) {
      cerr << "(" << i0 << ", " << j0 << "): quality mismatch: "
           << qual << "/" << count << endl;
      exit(1);
    }
  };

  for (int i = 0; i < N; i++) {
    qCheck(i, 0, 0, 1);
    qCheck(0, i, 1, 0);
  }


}
