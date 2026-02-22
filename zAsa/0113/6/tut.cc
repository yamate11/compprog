#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    using namespace std;
    unsigned N, M;
    cin >> N >> M;
    vector<unsigned> A(N);
    for (auto&& a : A)
        cin >> a;

    // 与えられた列の連続する 2 要素を選ばない部分列の総和を列挙する
    // 末尾の要素を使うものも同時に求める
    const auto solve{[M](const auto& seq) -> pair<vector<unsigned>, vector<unsigned>> {
        vector<unsigned> used, unused;
        unused.emplace_back();
        for (const auto x : seq) {
            swap(used, unused);
            for (auto&& v : used) {
                unused.emplace_back(v);
                (v += x) %= M;
            }
        }
        vector<unsigned> all(used);
        ranges::copy(unused, back_inserter(all));
        ranges::sort(used);
        ranges::sort(all);
        return make_pair(move(used), move(all));
    }};

    // 前半に対する結果
    const auto [first_used, first_all]{solve(A | views::take(N / 2))};
    // 後半に対する結果
    const auto [second_used, second_all]{solve(A | views::reverse | views::take((N + 1) / 2))};

    unsigned long ans{};
    for (const auto a : first_all)
        ans += ranges::upper_bound(second_all, (M - a) % M) - ranges::lower_bound(second_all, (M - a) % M);

    // 境界で連続しているものを引く
    for (const auto a : first_used)
        ans -= ranges::upper_bound(second_used, (M - a) % M) - ranges::lower_bound(second_used, (M - a) % M);

    cout << ans << endl;

    return 0;
}
