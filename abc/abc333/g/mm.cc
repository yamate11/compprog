#include <utility>
#include <vector>
#include <iostream>
#include <ranges>
#include <atcoder/modint>
#include <atcoder/math>

// -ad+bc = 1 であるような既約分数 x = a/b, y = c/d と有理数 r = p/q (x < r < y)について、
// p/q が a/b と c/d のどちらに近いかを判定する
//
// p/q - a/b < c/d - a/b = 1 / bd より
// (p/q - a/b) * qbd = pbd - qad が (0, q) の範囲の整数になることを利用し、適当な mod で評価したのち復元する
template<class Fraction>
bool compare(const Fraction &r, const Fraction &x, const Fraction &y) {
    const auto&[p, q]{r};
    const auto&[a, b]{x};
    const auto&[c, d]{y};

    using modint1 = atcoder::static_modint<1000000007>;
    using modint2 = atcoder::static_modint<1000000009>;

    std::vector<long long> reminder, modulo;
    reminder.emplace_back((modint1{p} * b * d - modint1{q} * a * d).val());
    modulo.emplace_back(modint1::mod());

    reminder.emplace_back((modint2{p} * b * d - modint2{q} * a * d).val());
    modulo.emplace_back(modint2::mod());

    // |r-x| <= |r-y| iff (p/q - a/b) * qbd <= q/2
    return atcoder::crt(reminder, modulo).first * 2 <= r.second;
}

int main() {
    using namespace std;
    using fraction = pair<unsigned long, unsigned long>;

    string r_str;
    unsigned long N;
    cin >> r_str >> N;

    // r を有理数に
    fraction r{0, 1};
    auto&&[p, q]{r};

    for (const auto digit : r_str | views::drop(2)) {
        (p *= 10) += digit - '0';
        q *= 10;
    }

    // 既約分数に直す
    {
        const auto g{gcd(p, q)};
        p /= g;
        q /= g;
    }

    // すでに分母・分子が N 以下ならそれが答え
    if (q <= N) {
        cout << p << " " << q << endl;
        return 0;
    }

    // x < r < y を満たす最大の x, 最小の y を求める
    const auto&[x, y]{[](const unsigned long N, fraction frac) -> pair<fraction, fraction> {
        auto&&[p, q]{frac};

        pair<unsigned long, unsigned long> numerator{1, 0}, denominator{0, 1};
        auto&&[n1, n2]{numerator};
        auto&&[d1, d2]{denominator};

        bool depth_parity{};
        // 連分数展開
        while (q) {
            const auto quo{p / q};
            const auto max_q{d1 ? (N - d2) / d1 : (N - n2) / n1};

            // 途中で N を越えるとき、x, y がわかる
            if (quo >= max_q)
                if (depth_parity)
                    return {{n1, d1}, {n1 * max_q + n2, d1 * max_q + d2}};
                else
                    return {{n1 * max_q + n2, d1 * max_q + d2}, {n1, d1}};

            numerator = make_pair(n1 * quo + n2, n1);
            denominator = make_pair(d1 * quo + d2, d1);
            frac = make_pair(q, p % q);

            depth_parity ^= 1;
        }
        return {};
    }(N, r)};

    if (compare(r, x, y)) // r <= (x+y)/2 なら
        // x を出力
        cout << x.first << " " << x.second << endl;
    else // そうでなければ
        // y を出力
        cout << y.first << " " << y.second << endl;

    return 0;
}
