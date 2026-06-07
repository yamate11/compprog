#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;

const int N = 20;
const int V = N * N;
const int OP_LIMIT = 100000;
const P EXIT = {0, 10};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> grid(N, vector<int>(N));
  vector<P> pos(V);

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> grid[r][c];
      pos[grid[r][c]] = {r, c};
    }
  }

  vector<vector<P>> belts;

  // 0: A 左側縦コンベア
  // (0,10)-(19,10)-(19,9)-(0,9)-(0,10)
  {
    vector<P> A;
    for (int r = 0; r < N; r++) A.push_back({r, 10});
    A.push_back({19, 9});
    for (int r = 18; r >= 0; r--) A.push_back({r, 9});
    belts.push_back(A);
  }

  // 1: B 右側縦コンベア
  // (0,10)-(19,10)-(19,11)-(0,11)-(0,10)
  {
    vector<P> B;
    for (int r = 0; r < N; r++) B.push_back({r, 10});
    B.push_back({19, 11});
    for (int r = 18; r >= 0; r--) B.push_back({r, 11});
    belts.push_back(B);
  }

  // 2..11: C0..C9 左側横コンベア
  // Ck: (2k,9)-(2k+1,9)-(2k+1,0)-(2k,0)-(2k,9)
  for (int k = 0; k < 10; k++) {
    int r = 2 * k;
    vector<P> C;
    C.push_back({r, 9});
    for (int c = 9; c >= 0; c--) C.push_back({r + 1, c});
    C.push_back({r, 0});
    for (int c = 1; c <= 8; c++) C.push_back({r, c});
    belts.push_back(C);
  }

  // 12..21: D0..D9 右側横コンベア
  // Dk: (2k,11)-(2k+1,11)-(2k+1,19)-(2k,19)-(2k,11)
  for (int k = 0; k < 10; k++) {
    int r = 2 * k;
    vector<P> D;
    D.push_back({r, 11});
    for (int c = 11; c <= 19; c++) D.push_back({r + 1, c});
    D.push_back({r, 19});
    for (int c = 18; c >= 12; c--) D.push_back({r, c});
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

  // -1: 未処理
  //  0: LA に載せた
  //  1: LB に載せた
  vector<int> staged_side(V, -1);

  // LA/LB．front が上側，back が下側のつもり。
  deque<int> lane[2];

  int x0 = 0; // 次に出口から出るべき箱
  int x1 = 0; // まだ処理していない最小の箱

  auto erase_from_lane = [&](int side, int x) {
    auto& q = lane[side];
    for (auto it = q.begin(); it != q.end(); ++it) {
      if (*it == x) {
        q.erase(it);
        return;
      }
    }
  };

  auto clear_stage = [&](int x) {
    if (0 <= x && x < V && staged_side[x] != -1) {
      int side = staged_side[x];
      erase_from_lane(side, x);
      staged_side[x] = -1;
    }
  };

  auto remove_if_possible = [&]() {
    while (x0 < V && grid[EXIT.first][EXIT.second] == x0) {
      grid[EXIT.first][EXIT.second] = -1;
      clear_stage(x0);
      x0++;
      if (x1 < x0) x1 = x0;
    }
  };

  auto apply_op = [&](int m, int d) -> bool {
    if (int(ops.size()) >= OP_LIMIT) return false;

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
    return true;
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

  auto side_col = [&](int side) -> int {
    // side 0: LA, A の 9列
    // side 1: LB, B の 11列
    return side == 0 ? 9 : 11;
  };

  auto belt_of_side = [&](int side) -> int {
    return side; // 0: A, 1: B
  };

  auto row_pos_on_lane = [&](int x, int side) -> int {
    auto [r, c] = pos[x];

    if (c == side_col(side)) return r / 2;

    // 列10にいる管理済みの箱は，本来「出口へ向かう途中」。
    // 退避判定では横コンベアに巻き込まれないので上にいる扱い。
    if (c == 10) return -1;

    // 想定外の場所にいる管理済み箱は，安全側に倒す。
    return 100;
  };

  auto max_lane_pos = [&](int side) -> int {
    int ret = -1;

    for (int x : lane[side]) {
      if (x < x0) continue;
      ret = max(ret, row_pos_on_lane(x, side));
    }

    return ret;
  };

  auto stage_box = [&](int x, int side) {
    if (staged_side[x] != -1) return;
    staged_side[x] = side;
    lane[side].push_back(x);
  };

  auto front_value_of_side = [&](int side) -> int {
    return grid[0][side_col(side)];
  };

  auto can_rotate_side = [&](int side) -> bool {
    int y = front_value_of_side(side);

    if (y < 0) return true;

    // LA/LB に載った箱が出口へ入るなら，それは x0 でなければならない。
    if (staged_side[y] != -1) return y == x0;

    // まだ LA/LB に載せていない箱は，一時的に出口セルを通っても許す。
    // これは「管理済み箱の順序」だけを守るため。
    return true;
  };

  auto rotate_side = [&](int side) -> bool {
    if (!can_rotate_side(side)) return false;
    return apply_op(belt_of_side(side), +1);
  };

  auto emit_x0_once = [&]() -> bool {
    if (x0 >= V) return false;

    int side = staged_side[x0];
    if (side == -1) return false;

    int before = x0;

    // A/B は長さ 40 なので，50 回で十分。
    for (int t = 0; t < 50 && x0 == before; t++) {
      if (!rotate_side(side)) return false;
    }

    return x0 != before;
  };

  auto emit_all_staged_in_order = [&]() -> bool {
    bool any = false;

    for (int loop = 0; loop < 1000; loop++) {
      if (x0 >= V) break;
      if (x0 >= x1) break;
      if (staged_side[x0] == -1) break;

      int before = x0;

      if (!emit_x0_once()) break;
      if (x0 == before) break;

      any = true;
    }

    return any;
  };

  auto move_box_on_belt = [&](int x, int m, P to) -> bool {
    if (!idx[m].count(pos[x])) return false;
    if (!idx[m].count(to)) return false;

    auto [cnt, dir] = dist_dir(m, pos[x], to);

    for (int t = 0; t < cnt; t++) {
      if (!apply_op(m, dir)) return false;
    }

    return true;
  };

  auto emit_until_side_can_rotate = [&](int side) -> bool {
    // side を回したいが，先頭に管理済みの非 x0 がいる場合，
    // 反対側などにいる x0 を先に出す。
    for (int loop = 0; loop < 200; loop++) {
      if (can_rotate_side(side)) return true;

      int before = x0;

      if (!emit_x0_once()) return false;
      if (x0 == before) return false;
    }

    return false;
  };

  auto ensure_lane_above_band = [&](int side, int i) -> bool {
    // lane[side] の最大位置 j が i 未満になるまで side を回す。
    // ただし side の先頭が管理済み非 x0 なら，先に x0 を出す。
    for (int loop = 0; loop < 200; loop++) {
      int j = max_lane_pos(side);

      if (j < i) return true;

      if (!emit_until_side_can_rotate(side)) return false;

      int before_x0 = x0;
      int before_ops = int(ops.size());

      if (!rotate_side(side)) return false;

      // 回した結果 x0 が出たら，次にまた side を回す前に，
      // 必要なら emit_until_side_can_rotate が順序を調整する。
      (void)before_x0;

      if (x0 == before_x0 && int(ops.size()) == before_ops) {
        return false;
      }
    }

    return false;
  };

  auto flush_all_queues = [&]() -> bool {
    // LA/LB に載っているものを番号順に全部出す。
    for (int loop = 0; loop < 5000; loop++) {
      if (x0 >= x1) return true;

      int before = x0;
      bool adv = emit_all_staged_in_order();

      if (!adv || x0 == before) return false;
    }

    return false;
  };

  auto stage_vertical_box_after_flush = [&](int x) -> bool {
    // x が A/B の縦コンベア上にある場合の安全策。
    // まず LA/LB を全部出してから，x を適当な lane に載せる。
    if (!flush_all_queues()) return false;

    if (x != x1) return true;
    if (x0 > x1) return true;

    P p = pos[x];
    int r = p.first;
    int c = p.second;

    if (c == 9) {
      stage_box(x, 0);
      x1++;
      return true;
    }

    if (c == 11) {
      stage_box(x, 1);
      x1++;
      return true;
    }

    if (c == 10) {
      // A/B の共有列にいる。空にした後なので，短い方へ載せる。
      int side = (lane[0].size() <= lane[1].size() ? 0 : 1);
      int target_col = side_col(side);

      // +1 方向で回せば，列10を下へ進み，底を回って side_col に入る。
      for (int loop = 0; loop < 50; loop++) {
        p = pos[x];
        if (p.second == target_col) {
          stage_box(x, side);
          x1++;
          return true;
        }

        if (!rotate_side(side)) return false;
      }

      return false;
    }

    return false;
  };

  remove_if_possible();

  for (long long main_iter = 0;
       main_iter < 300000 && x0 < V && int(ops.size()) < OP_LIMIT;
       main_iter++) {

    int old_x0 = x0;
    int old_x1 = x1;
    int old_ops = int(ops.size());

    if (x1 < x0) x1 = x0;

    if (x1 >= V) {
      flush_all_queues();
      break;
    }

    P p = pos[x1];
    int r = p.first;
    int c = p.second;

    bool ok = false;

    // すでに A/B の縦コンベア上にある場合。
    // これは安全策として，いったん LA/LB を全部吐き出してから x1 を載せる。
    if (c == 9 || c == 10 || c == 11) {
      ok = stage_vertical_box_after_flush(x1);
    }

    // 左側横コンベア C[i] 上。
    else if (c <= 8) {
      int i = r / 2;
      int side = 0;       // A, LA
      int m = 2 + i;      // C[i]

      if (ensure_lane_above_band(side, i)) {
        // A を回したことで x1 の位置が変わる可能性があるので取り直す。
        p = pos[x1];
        r = p.first;
        c = p.second;

        if (c <= 9) {
          i = r / 2;
          m = 2 + i;

          // C[i] で A の 9列，下側行に載せる。
          P target = {2 * i + 1, 9};

          if (move_box_on_belt(x1, m, target)) {
            stage_box(x1, side);
            x1++;
            ok = true;
          }
        }
      }
    }

    // 右側横コンベア D[i] 上。
    else if (c >= 12) {
      int i = r / 2;
      int side = 1;       // B, LB
      int m = 12 + i;     // D[i]

      if (ensure_lane_above_band(side, i)) {
        // B を回したことで x1 の位置が変わる可能性があるので取り直す。
        p = pos[x1];
        r = p.first;
        c = p.second;

        if (c >= 11) {
          i = r / 2;
          m = 12 + i;

          // D[i] で B の 11列，下側行に載せる。
          P target = {2 * i + 1, 11};

          if (move_box_on_belt(x1, m, target)) {
            stage_box(x1, side);
            x1++;
            ok = true;
          }
        }
      }
    }

    if (!ok) {
      // 詰まったら，まず管理済みキューを出せるだけ出す。
      bool adv = emit_all_staged_in_order();

      if (!adv) {
        // それでもだめなら，最後の安全策として，
        // 片側を安全に1回だけ回して状態を変える。
        bool moved = false;

        if (can_rotate_side(0)) moved = rotate_side(0);
        if (!moved && can_rotate_side(1)) moved = rotate_side(1);

        if (!moved) break;
      }
    }

    if (x0 == old_x0 && x1 == old_x1 && int(ops.size()) == old_ops) {
      break;
    }
  }

  // 最後に，まだキューに残っているものを出す。
  flush_all_queues();

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
