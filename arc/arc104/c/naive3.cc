#include <bits/stdc++.h>

int ri() {
  int n;
  scanf("%d", &n);
  return n;
}

bool solve() {
  int n = ri();
  int id[2 * n];
  for (auto &i : id) i = -1;
  int paired[2 * n];
  for (auto &i : paired) i = -1;
  for (int i = 0; i < n; i++) {
    int a = ri() - 1;
    int b = ri() - 1;
    if (a != -2 && b != -2 && a >= b) return false;
    if (a != -2) {
      if (id[a] != -1) return false;
      id[a] = i;
    }
    if (b != -2) {
      if (id[b] != -1) return false;
      id[b] = i;
    }
    if (a != -2 && b != -2) {
      paired[a] = b;
      paired[b] = a;
    }
  }
  bool ok[2 * n + 1];
  memset(ok, 0, sizeof(ok));
  ok[0] = 1;
  for (int i = 0; i < 2 * n; i++) {
    if (!ok[i]) continue;
    for (int j = 1; i + j * 2 <= 2 * n; j++) {
      bool t = true;
      for (int k = i; k < i + j; k++) if (id[k] != -1 && id[k + j] != -1 && id[k] != id[k + j]) { t = false; break; }
      for (int k = i; k < i + j; k++) if (id[k] != -1 && paired[k] != -1 && paired[k] != k + j) { t = false; break; }
      for (int k = i + j; k < i + j + j; k++) if (id[k] != -1 && paired[k] != -1 && paired[k] != k - j) { t = false; break; }
      if (t) ok[i + j * 2] = true;
    }
  }
  return ok[2 * n];
}

int main() {
  puts(solve() ? "Yes" : "No");
  return 0;
}
