#include <bits/stdc++.h>
using namespace std;

struct Op {
    int type, i, j, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R;
    cin >> R;

    vector<vector<int>> dep(R), sid(R);

    for (int r = 0; r < R; r++) {
        dep[r].resize(10);
        for (int c = 0; c < 10; c++) cin >> dep[r][c];
    }

    vector<vector<Op>> turns;

    // fixed[i] := 出発線 i の先頭から fixed[i] 両はすでに正しい，という意味
    vector<int> fixed(R, 0);

    auto apply_op = [&](const Op& op) {
        if (op.type == 0) {
            // departure i tail -> siding j head
            int i = op.i, j = op.j, k = op.k;

            assert(int(dep[i].size()) >= k);
            assert(int(sid[j].size()) + k <= 20);

            vector<int> seg(dep[i].end() - k, dep[i].end());
            dep[i].erase(dep[i].end() - k, dep[i].end());
            sid[j].insert(sid[j].begin(), seg.begin(), seg.end());
        } else {
            // siding j head -> departure i tail
            int i = op.i, j = op.j, k = op.k;

            assert(int(sid[j].size()) >= k);
            assert(int(dep[i].size()) + k <= 15);

            vector<int> seg(sid[j].begin(), sid[j].begin() + k);
            sid[j].erase(sid[j].begin(), sid[j].begin() + k);
            dep[i].insert(dep[i].end(), seg.begin(), seg.end());
        }
    };

    auto add_turn = [&](vector<Op> ops) {
        assert(!ops.empty());

        // 念のため，交差制約を確認
        vector<int> used_dep(R, 0), used_sid(R, 0);
        vector<pair<int, int>> pairs;

        for (auto& op : ops) {
            assert(0 <= op.type && op.type <= 1);
            assert(0 <= op.i && op.i < R);
            assert(0 <= op.j && op.j < R);
            assert(op.k >= 1);

            assert(!used_dep[op.i]);
            assert(!used_sid[op.j]);
            used_dep[op.i] = 1;
            used_sid[op.j] = 1;
            pairs.push_back({op.i, op.j});
        }

        sort(pairs.begin(), pairs.end());
        for (int p = 1; p < int(pairs.size()); p++) {
            assert(pairs[p - 1].first < pairs[p].first);
            assert(pairs[p - 1].second < pairs[p].second);
        }

        for (auto& op : ops) apply_op(op);
        turns.push_back(move(ops));
    };

    auto add_single = [&](int type, int i, int j, int k) {
        add_turn(vector<Op>{Op{type, i, j, k}});
    };

    auto locate_car = [&](int x) -> tuple<int, int, int> {
        // kind = 0: departure
        // kind = 1: siding
        for (int i = 0; i < R; i++) {
            for (int p = 0; p < int(dep[i].size()); p++) {
                if (dep[i][p] == x) return {0, i, p};
            }
        }
        for (int j = 0; j < R; j++) {
            for (int p = 0; p < int(sid[j].size()); p++) {
                if (sid[j][p] == x) return {1, j, p};
            }
        }
        assert(false);
        return {-1, -1, -1};
    };

    auto find_siding_cap_at_least = [&](int need) -> int {
        for (int j = 0; j < R; j++) {
            if (int(sid[j].size()) + need <= 20) return j;
        }
        return -1;
    };

    auto find_siding_with_space = [&]() -> int {
        for (int j = 0; j < R; j++) {
            if (int(sid[j].size()) < 20) return j;
        }
        assert(false);
        return -1;
    };

    auto find_departure_with_space = [&](int forbidden) -> int {
        for (int i = 0; i < R; i++) {
            if (i == forbidden) continue;
            if (int(dep[i].size()) < 15) return i;
        }
        return -1;
    };

    auto move_dep_tail_to_sidings = [&](int i, int len) {
        while (len > 0) {
            assert(int(dep[i].size()) - fixed[i] >= 1);

            int j = find_siding_with_space();
            int cap = 20 - int(sid[j].size());
            int q = min(len, cap);

            assert(q >= 1);
            assert(int(dep[i].size()) - fixed[i] >= q);

            add_single(0, i, j, q);
            len -= q;
        }
    };

    auto make_departure_space = [&](int forbidden) {
        // forbidden 以外の出発線に空きを作る．
        // fixed prefix は壊さず，その後ろだけを待避線へ逃がす．
        for (int i = 0; i < R; i++) {
            if (i == forbidden) continue;
            if (int(dep[i].size()) <= fixed[i]) continue;

            int j = find_siding_with_space();
            int cap = 20 - int(sid[j].size());
            int movable = int(dep[i].size()) - fixed[i];
            int q = min(movable, cap);

            if (q >= 1) {
                add_single(0, i, j, q);
                return;
            }
        }

        // 通常ここには来ない想定
        assert(false);
    };

    auto move_siding_prefix_to_departures = [&](int j, int len, int forbidden) {
        while (len > 0) {
            int i = find_departure_with_space(forbidden);
            if (i == -1) {
                make_departure_space(forbidden);
                i = find_departure_with_space(forbidden);
            }

            assert(i != -1);
            assert(i != forbidden);

            int cap = 15 - int(dep[i].size());
            int q = min(len, cap);

            assert(q >= 1);
            assert(int(sid[j].size()) >= q);

            add_single(1, i, j, q);
            len -= q;
        }
    };

    auto extract_from_departure_to_siding_head = [&](int x, int d, int pos) -> int {
        // dep[d][pos] == x を，どこかの待避線の先頭に出す．
        // 戻り値はその待避線番号．
        assert(dep[d][pos] == x);
        assert(pos >= fixed[d]);

        int suffix_len = int(dep[d].size()) - pos;

        // 可能なら x を含む suffix 全体を 1 回で待避線へ移す．
        // すると x はその待避線の先頭に来る．
        int j = find_siding_cap_at_least(suffix_len);
        if (j != -1) {
            add_single(0, d, j, suffix_len);
            assert(!sid[j].empty());
            assert(sid[j].front() == x);
            return j;
        }

        // 容量が足りなければ，まず x より後ろだけを逃がし，
        // 最後に x を 1 両だけ待避線へ移す．
        int tail_after = int(dep[d].size()) - pos - 1;
        move_dep_tail_to_sidings(d, tail_after);

        assert(!dep[d].empty());
        assert(dep[d].back() == x);

        j = find_siding_with_space();
        add_single(0, d, j, 1);

        assert(!sid[j].empty());
        assert(sid[j].front() == x);
        return j;
    };

    auto bring_siding_car_to_head = [&](int x, int j, int forbidden_dep) {
        // sid[j] 内の x より前にある車両を出発線へ逃がして，
        // x を sid[j] の先頭に出す．
        int pos = -1;
        for (int p = 0; p < int(sid[j].size()); p++) {
            if (sid[j][p] == x) {
                pos = p;
                break;
            }
        }

        assert(pos != -1);

        if (pos > 0) {
            move_siding_prefix_to_departures(j, pos, forbidden_dep);
        }

        assert(!sid[j].empty());
        assert(sid[j].front() == x);
    };

    for (int x = 0; x < 10 * R; x++) {
        int r = x / 10;
        int c = x % 10;

        assert(fixed[r] == c);

        for (int p = 0; p < fixed[r]; p++) {
            assert(dep[r][p] == 10 * r + p);
        }

        // すでに正しい位置にいるなら，そのまま固定を 1 つ伸ばす．
        if (int(dep[r].size()) > c && dep[r][c] == x) {
            fixed[r]++;
            continue;
        }

        // 目標出発線 r を，固定済み prefix だけ残して空ける．
        // ここで x 自身が r にいた場合も，いったん待避線へ出される．
        if (int(dep[r].size()) > c) {
            int len = int(dep[r].size()) - c;
            move_dep_tail_to_sidings(r, len);
        }

        assert(int(dep[r].size()) == c);

        auto [kind, line, pos] = locate_car(x);

        int from_siding = -1;

        if (kind == 0) {
            // 出発線にいるなら，x を含む suffix を待避線へ出して，
            // x を待避線の先頭にする．
            from_siding = extract_from_departure_to_siding_head(x, line, pos);
        } else {
            // 待避線にいるなら，x より前を出発線へ逃がして，
            // x を待避線の先頭にする．
            from_siding = line;
            bring_siding_car_to_head(x, from_siding, r);
        }

        assert(!sid[from_siding].empty());
        assert(sid[from_siding].front() == x);
        assert(int(dep[r].size()) == c);

        // x を正しい出発線の末尾へ移す．
        add_single(1, r, from_siding, 1);

        assert(int(dep[r].size()) == c + 1);
        assert(dep[r][c] == x);

        fixed[r]++;
    }

    for (int r = 0; r < R; r++) {
        assert(int(dep[r].size()) == 10);
        for (int c = 0; c < 10; c++) {
            assert(dep[r][c] == 10 * r + c);
        }
    }

    assert(int(turns.size()) <= 4000);

    cout << turns.size() << '\n';
    for (auto& ops : turns) {
        cout << ops.size() << '\n';
        for (auto& op : ops) {
            cout << op.type << ' ' << op.i << ' ' << op.j << ' ' << op.k << '\n';
        }
    }

    return 0;
}
