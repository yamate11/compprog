

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int D = 365; // 日数
constexpr int CN = 26; // コンテストの種類数
int c[CN];             // コンテストの満足度の下がりやすさ
int s[D][CN];          // ある日付にコンテストを開催したときの満足度の増加量
array<array<pair<int, int>, CN>, D> s_contests;

void input()
{
    int _;
    cin >> _;
    for (int i = 0; i < CN; i++)
        cin >> c[i];
    for (int i = 0; i < D; i++)
        for (int j = 0; j < CN; j++)
        {
            cin >> s[i][j];
            s_contests[i][j] = {s[i][j], j};
        }
}

void preprocess()
{
    for (int i = 0; i < D; i++)
    {
        sort(s_contests[i].begin(), s_contests[i].end(), greater<pair<int, int>>());
    }
}

constexpr const long long int INF = 1000000000LL; // あり得ないぐらい大きなスコアの例を用意しておく
constexpr int W = 20;                             // ハンガリアン法で「W日間は同じコンテストを開催しない」とする
// ハンガリアン法用
constexpr int N = W;  // ハンガリアン法で少ない法の集合の頂点数
constexpr int M = CN; // ハンガリアン法で多い方の集合の頂点数

// コンテストが開催されなかった期間の満足度の下がり具合は、
// c[i]*(1+2+3+...+(elapsed-1))
// で表される
// (1+2+3+...+(elapsed-1))は、和の公式により
// elapsed*(elapsed-1)/2
// と計算できるので、これを計算する
inline int day_cumsum(const int last_day, const int now_day)
{
    int elapsed = now_day - last_day;
    return elapsed * (elapsed - 1) / 2;
}

struct State
{
    long long int evaluated_score_; // 探索上で評価したスコア
    int day_;                       // 日付
    vector<int> elapsed_;           // 各コンテストが開催されていない期間
    vector<int> contests_;          // 各日付に開催予定のコンテスト
    State()
    {
        evaluated_score_ = 1e6;
        day_ = 0;
        elapsed_ = vector<int>(CN, 0);
        contests_ = vector<int>(D);
    }

    // 終了判定
    bool isDone() const
    {
        return this->day_ == D;
    }

    // 指定したactionで状態を1ステップ進め、評価する
    void advance(const int action)
    {
        this->evaluated_score_ += s[this->day_][action];
        this->elapsed_[action] = 0;
        this->contests_[this->day_] = action;
        for (int i = 0; i < CN; i++)
        {
            if (i == action)
            {
                continue;
            }
            this->elapsed_[i]++;
            // this->evaluated_score_ -= c[i] * elapsed_[i];
        }
        ++this->day_;
        this->evaluated_score_ = this->evaluate_hungarian();
    }

    // input : N * M cost matrix (bipatite graph)
    // output : {cost, matching} size-N matching with minimum cost
    // constraint : N <= M, time : O(N^2 M)
    int weights_[N][M]; // N=W, M=CN 日付とコンテストのマッチングの重み(満足度の損失)
    vector<int> hungarian()
    {
        constexpr int n = N + 1, m = M + 1;
        assert(n <= m);
        vector<int> u(n), v(m), p(m), ans(n - 1);
        for (int i = 1; i < n; i++)
        {
            p[0] = i;
            int j0 = 0; // add "dummy" worker 0
            vector<int> dist(m, INT_MAX), pre(m, -1);
            vector<bool> done(m + 1);
            do
            { // dijkstra
                done[j0] = true;
                int i0 = p[j0], j1, delta = INT_MAX;
                for (int j = 1; j < m; j++)
                    if (!done[j])
                    {
                        int cur = weights_[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < dist[j])
                            dist[j] = cur, pre[j] = j0;
                        if (dist[j] < delta)
                            delta = dist[j], j1 = j;
                    }
                for (int j = 0; j < m; j++)
                {
                    if (done[j])
                        u[p[j]] += delta, v[j] -= delta;
                    else
                        dist[j] -= delta;
                }
                j0 = j1;
            } while (p[j0]);
            while (j0)
            { // update alternating path
                int j1 = pre[j0];
                p[j0] = p[j1], j0 = j1;
            }
        }
        for (int j = 1; j < m; j++)
            if (p[j])
                ans[p[j] - 1] = j - 1;
        return ans; // min cost
    }
    vector<int> make_contest(int day, vector<int> &elapsed)
    {
        const int W = min(::W, D - day);
        memset(weights_, 0x00, sizeof weights_);
        for (int w = 0; w < W; w++)
        {
            for (int t = 0; t < CN; t++)
            {
                auto elapsed_whole = elapsed[t] + w;
                auto future_elapsed = W - w;
                // 元の満足度低下 = (elapsed_whole+future_elapsed)*(elapsed_whole+future_elapsed+1)/2
                // 新しい満足度低下 = elapsed_whole*(elapsed_whole+1)/2 + future_elapsed*(future_elapsed+1)/2
                // 満足度の増加量=s[day + w][t] - c[t]*(元の満足度低下 - 新しい満足度低下)
                // 上の式を代入して計算すると(元の満足度低下 - 新しい満足度低下)= elapsed_whole * future_elapsed
                weights_[w][t] = -(s[day + w][t] + c[t] * elapsed_whole * future_elapsed);
            }
        }
        return hungarian();
    }

    int evaluate_hungarian()
    {
        vector<int> contests = contests_;
        vector<int> elapsed = elapsed_;
        auto tmp_max = min(D, day_ + W);
        int day = day_;
        for (int &l : elapsed)
            l++;
        const vector<int> ts = make_contest(day, elapsed);
        for (int ti = 0; ti < W; ti++)
        {
            if (day + ti >= D)
            {
                break;
            }
            contests[day + ti] = ts[ti];
            elapsed[ts[ti]] = 0;
        }
        auto score = compute_whole_score(contests, tmp_max);
        return score;
    }
    // スコアを差分ではなく全体で計算する
    int compute_whole_score(const vector<int> &contests, const int tmp_max)
    {
        int satisfy = 1e6;
        vector<int> lst(CN);
        for (int d = 0; d < tmp_max; d++)
        {
            int bef_lst = lst[contests[d]];
            lst[contests[d]] = d + 1;
            satisfy += s[d][contests[d]];
            satisfy -= c[contests[d]] * day_cumsum(bef_lst, d + 1);
        }
        for (int i = 0; i < CN; i++)
        {
            satisfy -= c[i] * day_cumsum(lst[i], tmp_max + 1);
        }
        return satisfy;
    }

    // 現在の状態から探索対象にする操作を取得する
    vector<int> legalActions() const
    {
        vector<int> actions{};
        // auto thresholed = s_contests[this->day_][0].first * 0.8;
        vector<pair<int, int>> score_actions;
        for (int action = 0; action < CN; action++)
        {
            auto score = s[this->day_][action] + c[action] * elapsed_[action];
            score_actions.emplace_back(score, action);
        }
        const int limit = min(8, CN);
        partial_sort(score_actions.begin(), score_actions.begin() + limit, score_actions.end(), greater<pair<int, int>>());
        for (int ai = 0; ai < limit; ai++)
        {
            actions.emplace_back(score_actions[ai].second);
        }
        return actions;
    }
};

// 貪欲法で操作列を決定する
vector<int> greedy(const State &state)
{
    vector<int> best_actions{};
    State now_state = state;
    while (!now_state.isDone())
    {
        long long int best_score = -INF; // 絶対にありえない小さな値でベストスコアを初期化する
        int best_action = -1;            // ありえない操作で初期化する
        auto legal_actions = now_state.legalActions();
        for (const auto action : legal_actions)
        {
            auto next_state = now_state;
            next_state.advance(action);
            if (next_state.evaluated_score_ > best_score)
            {
                best_score = next_state.evaluated_score_;
                best_action = action;
            }
        }
        best_actions.emplace_back(best_action);
        now_state.advance(best_action);
    }
    return best_actions;
}

void output(const vector<int> &actions)
{
    for (const auto action : actions)
    {
        cout << action + 1 << endl;
    }
}

int main()
{
    cerr << "プログラム開始" <<endl;
    input();
    preprocess();
    cerr << "入力読み取り完了" <<endl;
    State state{};
    cerr << "状態初期化完了" <<endl;
    auto actions = greedy(state);
    cerr << "回答生成完了" <<endl;
    output(actions);
    cerr << "出力完了" <<endl;
    return 0;
}