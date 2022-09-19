int main() {
  REP(i, 0, N) REP(j, 0, N) {
    bool equal1 = true;
    REP(k, 0, M) {
      bool equal2 = true;
      REP(l, 0, M) {
        if (A[i + k][j + l] != B[k][l]) {
          equal2 = false;
          break;
        }
      }
      if (!equal2) {
        equal1 = false;
        break;
      }
    }
    if (equal1) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}

int main3() {
  bool ans = false;
  REP(i, 0, N) REP(j, 0, N) {
    bool equal = true;
    REP(k, 0, M) REP(l, 0, M) if (A[i + k][j + l] != B[k][l]) equal = false;
    ans = ans || equal;
  }
  cout << (ans ? "Yes\n" : "No\n");
  return 0;
}

int main2() {
  cout << (EXISTS(i, 0, N,
             EXISTS(j, 0, N,
               FORALL(k, 0, M,
                 FORALL(l, 0, M, 
                   A[i + k][j + l] != B[k][l])))) ?
           "Yes\n" : "No\n");
  return 0;
}
