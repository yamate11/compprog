

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
constexpr int BEAM_WIDTH = 70;
constexpr int LEGAL_ACTION_LIMIT = 8;
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
    array<int, CN> elapsed_;        // 各コンテストが開催されていない期間
    array<int, D> contests_;        // 各日付に開催予定のコンテスト
    vector<int> actions_;           // 操作の履歴
    int ref_count_ = 0;             // 参照カウンタ
    State()
    {
        evaluated_score_ = 1e6;
        day_ = 0;
        elapsed_.fill(0);
        // contests_ は未初期化のままでよい（評価時に上書き）
        actions_.reserve(D); // 再確保の削減
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
        int u[n] = {0};
        int v[m] = {0};
        int p[m] = {0};
        vector<int> ans(n - 1);
        for (int i = 1; i < n; i++)
        {
            p[0] = i;
            int j0 = 0; // add "dummy" worker 0
            int dist[m];
            int pre[m];
            bool done[m + 1];
            for (int di = 0; di < m; ++di)
            {
                dist[di] = INT_MAX;
                pre[di] = -1;
            }
            for (int di = 0; di <= m; ++di)
            {
                done[di] = false;
            }
            do
            { // dijkstra
                done[j0] = true;
                int i0 = p[j0], j1 = 0, delta = INT_MAX;
                for (int j = 1; j < m; j++)
                    if (!done[j])
                    {
                        int cur = weights_[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < dist[j])
                            dist[j] = cur, pre[j] = j0;
                        if (dist[j] < delta)
                            delta = dist[j], j1 = j;
                    }
                if (delta == INT_MAX)
                    break;
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
    vector<int> make_contest(int day, array<int, CN> &elapsed)
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
        array<int, D> contests = contests_;
        array<int, CN> elapsed = elapsed_;
        auto tmp_max = min(D, day_ + W);
        int day = day_;
        for (int i = 0; i < CN; ++i)
            elapsed[i]++;
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
    int compute_whole_score(const array<int, D> &contests, const int tmp_max)
    {
        int satisfy = 1e6;
        int lst[CN] = {0};
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
        const int limit = min(LEGAL_ACTION_LIMIT, CN);
        // 上位Kのみ保持する小さいヒープ（最小ヒープ）
        using P = pair<int, int>;
        auto cmp = [](const P &a, const P &b)
        { return a.first > b.first; };
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        for (int action = 0; action < CN; action++)
        {
            int score = s[this->day_][action] + c[action] * elapsed_[action];
            if ((int)pq.size() < limit)
            {
                pq.emplace(score, action);
            }
            else if (score > pq.top().first)
            {
                pq.pop();
                pq.emplace(score, action);
            }
        }
        vector<int> actions;
        actions.reserve(limit);
        // 大きい順に並べ替えて返す
        vector<P> tmp;
        tmp.reserve(pq.size());
        while (!pq.empty())
        {
            tmp.emplace_back(pq.top());
            pq.pop();
        }
        sort(tmp.begin(), tmp.end(), [](const P &a, const P &b)
             { return a.first > b.first; });
        for (auto &p : tmp)
            actions.emplace_back(p.second);
        return actions;
    }
    // 参照カウントを初期化する
    void init()
    {
        ref_count_ = 1;
    }
    // 参照カウントをインクリメントする
    void addRef()
    {
        ++ref_count_;
    }
    // 参照カウントをデクリメントする。参照がなくなったら破棄する
    void release()
    {
        if (ref_count_ == 1)
        {
            delete (this);
        }
        else
        {
            --ref_count_;
        }
    }
};

bool operator>(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ > state_2.evaluated_score_;
}
bool operator<(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ < state_2.evaluated_score_;
}

struct StatePtr
{
    State *state;
    StatePtr(const State &state)
    {
        this->state = new State();
        *this->state = state;
        this->state->init();
    }
    StatePtr(const StatePtr &state_ptr)
    {
        this->state = state_ptr.state;
        this->state->addRef();
    }
    void operator=(const StatePtr &state_ptr)
    {
        this->state->release();
        this->state = state_ptr.state;
        this->state->addRef();
    }
    ~StatePtr()
    {
        this->state->release();
    }
};
bool operator<(const StatePtr &state_ptr1, const StatePtr &state_ptr2)
{
    return (*state_ptr1.state) < (*state_ptr2.state);
}

// ビーム幅を指定してビームサーチで操作列を決定する
vector<int> beamSearch(
    const State &state,
    const int beam_width)
{
    priority_queue<StatePtr> now_beam;
    State best_state;

    now_beam.emplace(state);
    for (int t = 0;; t++)
    {
        // next_beam はサイズを beam_width に制限する最大ヒープ（最小を捨てる）
        auto cmp = [](const StatePtr &a, const StatePtr &b)
        {
            return (*a.state).evaluated_score_ > (*b.state).evaluated_score_;
        };
        priority_queue<StatePtr, vector<StatePtr>, decltype(cmp)> next_beam(cmp);
        for (int i = 0; i < beam_width; i++)
        {
            if (now_beam.empty())
                break;
            State now_state = *now_beam.top().state;
            now_beam.pop();
            auto legal_actions = now_state.legalActions();
            for (const auto &action : legal_actions)
            {
                State next_state = now_state;
                next_state.advance(action);
                next_state.actions_.emplace_back(action);
                next_beam.emplace(next_state);
                // サイズ制限：beam_width を超えたら最悪要素を捨てる
                if ((int)next_beam.size() > beam_width)
                {
                    next_beam.pop();
                }
            }
        }

        // now_beam を作り直す
        now_beam = priority_queue<StatePtr>();
        while (!next_beam.empty())
        {
            now_beam.emplace(*next_beam.top().state);
            next_beam.pop();
        }
        best_state = *now_beam.top().state;

        if (best_state.isDone())
        {
            break;
        }
    }
    return best_state.actions_;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    preprocess();
    State state{};
    auto actions = beamSearch(state, BEAM_WIDTH);
    output(actions);
    return 0;
}