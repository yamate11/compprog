#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;

const int N = 20;
const int V = N * N;
const P EXIT = {0, 10};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> grid(N, vector<int>(N));
  vector<P> pos(V);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
      pos[grid[i][j]] = {i, j};
    }
  }

  vector<vector<P>> belts;

  // 0: A
  // (0,10)-(19,10)-(19,11)-(0,11)-(0,10)
  vector<P> A;
  for (int r = 0; r < N; r++) A.push_back({r, 10});
  A.push_back({19, 11});
  for (int r = 18; r >= 0; r--) A.push_back({r, 11});
  belts.push_back(A);

  // 1: B
  // (0,10)-(19,10)-(19,9)-(0,9)-(0,10)
  vector<P> B;
  for (int r = 0; r < N; r++) B.push_back({r, 10});
  B.push_back({19, 9});
  for (int r = 18; r >= 0; r--) B.push_back({r, 9});
  belts.push_back(B);

  // 2..11: C0..C9
  // Ck: (2k,11)-(2k+1,11)-(2k+1,19)-(2k,19)-(2k,11)
  for (int k = 0; k < 10; k++) {
    int r = 2 * k;
    vector<P> C;

    C.push_back({r, 11});
    for (int c = 11; c <= 19; c++) C.push_back({r + 1, c});
    C.push_back({r, 19});
    for (int c = 18; c >= 12; c--) C.push_back({r, c});

    belts.push_back(C);
  }

  // 12..21: D0..D9
  // Dk: (2k,9)-(2k+1,9)-(2k+1,0)-(2k,0)-(2k,9)
  for (int k = 0; k < 10; k++) {
    int r = 2 * k;
    vector<P> D;

    D.push_back({r, 9});
    for (int c = 9; c >= 0; c--) D.push_back({r + 1, c});
    D.push_back({r, 0});
    for (int c = 1; c <= 8; c++) D.push_back({r, c});

    belts.push_back(D);
  }

  const int M = int(belts.size());

  vector<map<P,int>> idx(M);
  for (int m = 0; m < M; m++) {
    for (int i = 0; i < int(belts[m].size()); i++) {
      idx[m][belts[m][i]] = i;
    }
  }

  vector<pair<int,int>> ops;

  // -1: まだ A/B 側に準備していない
  //  0: A 側，11列に積んだ
  //  1: B 側，9列に積んだ
  vector<int> staged_side(V, -1);

  int next_box = 0;
  int prepare = 0;

  auto clear_stage = [&](int x) {
    if (0 <= x && x < V) staged_side[x] = -1;
  };

  auto remove_if_possible = [&]() {
    while (next_box < V) {
      auto [er, ec] = EXIT;
      if (grid[er][ec] != next_box) break;

      grid[er][ec] = -1;
      clear_stage(next_box);
      next_box++;

      if (prepare < next_box) prepare = next_box;
    }
  };

  auto apply_op = [&](int m, int d) {
    if ((int)ops.size() >= 100000) return;

    const auto& b = belts[m];
    int L = int(b.size());

    vector<int> oldv(L), newv(L);

    for (int i = 0; i < L; i++) {
      auto [r, c] = b[i];
      oldv[i] = grid[r][c];
    }

    for (int i = 0; i < L; i++) {
      int ni = (i + d + L) % L;
      newv[ni] = oldv[i];
    }

    for (int i = 0; i < L; i++) {
      auto [r, c] = b[i];
      grid[r][c] = newv[i];
      if (newv[i] >= 0) pos[newv[i]] = {r, c};
    }

    ops.push_back({m, d});
    remove_if_possible();
  };

  auto dist_dir = [&](int m, P from, P to) -> pair<int,int> {
    int L = int(belts[m].size());
    int s = idx[m].at(from);
    int t = idx[m].at(to);

    int plus = (t - s + L) % L;
    int minus = (s - t + L) % L;

    if (plus <= minus) return {plus, +1};
    else return {minus, -1};
  };

  auto move_box_on_belt = [&](int x, int m, P to) {
    P from = pos[x];

    auto [cnt, dir] = dist_dir(m, from, to);

    for (int i = 0; i < cnt; i++) {
      if ((int)ops.size() >= 100000) return;
      apply_op(m, dir);
    }
  };

  auto side_row = [&](int x, int side) -> int {
    auto [r, c] = pos[x];

    if (side == 0) {
      // A 側の待ち行列は 11 列。
      if (c == 11) return r;
    } else {
      // B 側の待ち行列は 9 列。
      if (c == 9) return r;
    }

    // 列10にいるものは，横コンベア C/D には巻き込まれない扱い。
    if (c == 10) return -1;

    // それ以外にいる staged な箱は本来あまりないが，安全側に倒す。
    return 100;
  };

  auto emit_one_staged = [&]() -> bool {
    if (next_box >= V) return false;

    int x = next_box;
    int side = staged_side[x];

    if (side == -1) return false;

    int belt = side;  // 0: A, 1: B
    int before = next_box;

    // A/B に積んだものは，常に +1 方向で出口へ向かわせる。
    while (next_box == before && (int)ops.size() < 100000) {
      apply_op(belt, +1);
    }

    return next_box != before;
  };

  auto drain_staged_in_order = [&]() {
    // すでに A/B 側に準備済みの箱を，番号順に出せるだけ出す。
    while (next_box < prepare && staged_side[next_box] != -1) {
      bool ok = emit_one_staged();
      if (!ok) break;
    }
  };

  auto ensure_queue_clear_band = [&](int side, int band_top_row) {
    // これから Ck/Dk を回すなら，既に同じ側に積んだ小さい番号は
    // その 2 行帯 [2k, 2k+1] から完全に退避していなければならない。
    //
    // side=0: A 側。A を +1 で回す。
    // side=1: B 側。B を +1 で回す。
    int belt = side;

    while ((int)ops.size() < 100000) {
      bool ok = true;

      for (int x = next_box; x < prepare; x++) {
        if (staged_side[x] != side) continue;

        int r = side_row(x, side);

        // r == -1 は列10上なので，C/D の横コンベアには巻き込まれない。
        if (r >= band_top_row) {
          ok = false;
          break;
        }
      }

      if (ok) break;

      int before = next_box;

      // 退避のために 1 回だけ回す。
      apply_op(belt, +1);

      // 退避中に next_box が出たら，そのまま同じ側を回し続けてはいけない。
      // A/B に分かれている待ち行列を，全体の番号順で吐けるだけ吐く。
      if (next_box != before) {
        drain_staged_in_order();
      }
    }
  };

  remove_if_possible();

  int fail_count = 0;

  while (next_box < V && (int)ops.size() < 100000) {
    if (prepare < next_box) prepare = next_box;

    // すでに準備済みの next_box があるなら，先に番号順に吐けるだけ吐く。
    drain_staged_in_order();

    if (next_box >= V || (int)ops.size() >= 100000) break;
    if (prepare < next_box) prepare = next_box;

    if (prepare >= V) {
      bool ok = emit_one_staged();
      if (!ok) break;
      drain_staged_in_order();
      continue;
    }

    int x = prepare;
    P p = pos[x];
    auto [r, c] = p;

    bool prepared = false;

    if (c >= 11) {
      int k = r / 2;
      int m = 2 + k;       // Ck
      int band_top_row = 2 * k;
      int insert_row = 2 * k + 1;

      // 既に A 側に積んだ小さい番号を，Ck の 2 行帯より上へ退避。
      ensure_queue_clear_band(0, band_top_row);
      drain_staged_in_order();

      if ((int)ops.size() >= 100000) break;

      // A を動かしたことで x の位置が変わった可能性があるので取り直す。
      p = pos[x];
      r = p.first;
      c = p.second;

      // まだ同じ Ck 上にいるなら，Ck を回して A 側の 11列へ載せる。
      if (c >= 11 && r / 2 == k && idx[m].count(p)) {
        move_box_on_belt(x, m, {insert_row, 11});

        staged_side[x] = 0;
        prepare++;
        prepared = true;
        fail_count = 0;

        drain_staged_in_order();
      }
    } else if (c <= 9) {
      int k = r / 2;
      int m = 12 + k;      // Dk
      int band_top_row = 2 * k;
      int insert_row = 2 * k + 1;

      // 既に B 側に積んだ小さい番号を，Dk の 2 行帯より上へ退避。
      ensure_queue_clear_band(1, band_top_row);
      drain_staged_in_order();

      if ((int)ops.size() >= 100000) break;

      // B を動かしたことで x の位置が変わった可能性があるので取り直す。
      p = pos[x];
      r = p.first;
      c = p.second;

      // まだ同じ Dk 上にいるなら，Dk を回して B 側の 9列へ載せる。
      if (c <= 9 && r / 2 == k && idx[m].count(p)) {
        move_box_on_belt(x, m, {insert_row, 9});

        staged_side[x] = 1;
        prepare++;
        prepared = true;
        fail_count = 0;

        drain_staged_in_order();
      }
    } else {
      // 列10にいる場合。
      // まだ staged でないなら，A/B のどちらかで吐き出し側に回せる位置にいる。
      // ここでは next_box ならそのまま出るのを期待して回す。
      // prepare 番が列10にいるが next_box でないケースは，待ち行列との干渉がありうるので
      // drain と安全弁に任せる。
    }

    if (prepared) continue;

    // ここに来るのは，
    // - prepare 番が列10にいる
    // - A/B を動かした結果，もとの Ck/Dk から外れた
    // - 既存の待ち行列処理で状況が変わった
    // など。
    //
    // まず番号順に出せるものを出す。
    int before = next_box;
    drain_staged_in_order();

    if (next_box != before) {
      fail_count = 0;
      continue;
    }

    // まだ出せない場合の雑な安全弁。
    // A/B を交互に 1 回動かして状況を変える。
    // ただし，この安全弁はあくまで停止回避用で，品質はよくない。
    fail_count++;

    if ((int)ops.size() >= 100000) break;

    if (fail_count % 2 == 1) apply_op(0, +1);
    else apply_op(1, +1);

    drain_staged_in_order();
  }

  cout << M << '\n';
  for (int m = 0; m < M; m++) {
    cout << belts[m].size();
    for (auto [r, c] : belts[m]) {
      cout << ' ' << r << ' ' << c;
    }
    cout << '\n';
  }

  cout << ops.size() << '\n';
  for (auto [m, d] : ops) {
    cout << m << ' ' << d << '\n';
  }

  return 0;
}
