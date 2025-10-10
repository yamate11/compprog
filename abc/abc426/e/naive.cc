#include <bits/stdc++.h>

using namespace std;

using P = pair<int, int>;
using Pd = pair<double, double>;

// |a - b| ^ 2
int dist_sq(P a, P b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

// a - b
Pd sub(Pd a, Pd b) {
    return {a.first - b.first, a.second - b.second};
}

// |a - b|
double dist(Pd a, Pd b) {
    Pd d = sub(a, b);
    return sqrt(d.first * d.first + d.second * d.second);
}

// a + (b - a) * p
Pd internal_division(Pd a, Pd b, double p) {
    double x = a.first + (b.first - a.first) * p;
    double y = a.second + (b.second - a.second) * p;
    return {x, y};
}

const int NUM_ITERATION = 100;

// distance between the origin and the segment AB
double dist_segment_and_origin(Pd a, Pd b) {
    auto f = [&](double p) {
        return dist(internal_division(a, b, p), {0, 0});
    };
    double l = 0, r = 1;
    for (int i = 0; i < NUM_ITERATION; i++) {
        double ml = (l * 2 + r) / 3;
        double mr = (l + r * 2) / 3;
        if (f(ml) < f(mr)) r = mr;
        else l = ml;
    }
    return f(l);
}

void solve() {
    vector<P> s(2), g(2);
    for (int i = 0; i < 2; i++) {
        cin >> s[i].first >> s[i].second >> g[i].first >> g[i].second;
    }
    if (dist_sq(s[0], g[0]) < dist_sq(s[1], g[1])) {
        swap(s[0], s[1]);
        swap(g[0], g[1]);
    }
    Pd ts = s[0], tg = g[0], as = s[1], ag = g[1];
    Pd tm = internal_division(ts, tg, dist(as, ag) / dist(ts, tg));
    assert(abs(dist(ts, tm) - dist(as, ag)) < 1e-9);
    double d1 = dist_segment_and_origin(sub(ts, as), sub(tm, ag));
    double d2 = dist_segment_and_origin(sub(tm, ag), sub(tg, ag));
    cout << min(d1, d2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cout << fixed << setprecision(15);
    while (t--) solve();
}
