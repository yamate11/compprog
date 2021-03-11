#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

const int maxn = 110;
const int maxs = 110;
constexpr ll INF = TEN(18);

int main() {
    int N;
    cin >> N;
    V<string> S(N);
    V<int> C(N);
    map<string, int> sid;
    sid[""] = 0;  // goal

    rep(i, N) {
        cin >> S[i] >> C[i];
        {
            string t;
            rep(j, S[i].size()) {
                t.pb(S[i][j]);
                if (!sid.count(t)) {
                    int sz = sid.size();
                    sid[t] = sz;
                }
            }
        }
        {
            string t;
            per(j, S[i].size()) {
                t = S[i][j] + t;
                if (!sid.count(t)) {
                    int sz = sid.size();
                    sid[t] = sz;
                }
            }
        }
    }

    int sz = sid.size();

    V<string> tos(sz);
    V<bool> is_pal(sz);
    for (auto p : sid) {
        tos[p.se] = p.fi;
        auto t = p.fi;
        reverse(ALL(t));
        is_pal[p.se] = (t == p.fi);
    }

    debug(tos);

    VV<ll> d(2, V<ll>(sz, INF));
    using Data = pair<ll, pii>;  // cost, (direction, string id)

    priority_queue<Data, V<Data>, greater<Data>> que;

    ll ans = INF;

    rep(i, N) {
        {
            auto t = S[i];
            reverse(ALL(t));
            if (S[i] == t) {
                chmin(ans, C[i]);
                continue;
            }
        }

        int id = sid[S[i]];
        rep(j, 2) {
            if (d[j][id] > C[i]) {
                d[j][id] = C[i];
                que.push(mp(C[i], mp(j, id)));
            }
        }
    }

    while (!que.empty()) {
        auto data = que.top();
        que.pop();
        int dir, id;
        tie(dir, id) = data.se;
        if (d[dir][id] < data.fi) continue;

        // debug(d[dir][id], tos[id], dir);

        rep(i, N) {  // another side
            string s = tos[id], t = S[i];
            if (dir) swap(s, t);  // s:left,t:right

            int l = 0;
            while (l < min(s.size(), t.size())) {
                if (s[l] == t[t.size() - 1 - l]) {
                    l++;
                } else {
                    break;
                }
            }
            // NG
            if (l < min(s.size(), t.size())) continue;
            // debug(s, t, l);

            ll nd = d[dir][id] + C[i];
            if (l == s.size() && l == t.size()) {
                chmin(ans, nd);
            } else if (l == s.size()) {
                string rem = t.substr(0, t.size() - l);
                debug(rem);
                int nid = sid[rem];
                if (is_pal[nid]) chmin(ans, nd);
                if (d[1][nid] > nd) {
                    d[1][nid] = nd;
                    que.push(mp(nd, mp(1, nid)));
                }
            } else {
                string rem = s.substr(l, s.size() - l);
                debug(rem);
                int nid = sid[rem];
                if (is_pal[nid]) chmin(ans, nd);
                if (d[0][nid] > nd) {
                    d[0][nid] = nd;
                    que.push(mp(nd, mp(0, nid)));
                }
            }
        }
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
