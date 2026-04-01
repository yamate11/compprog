

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int D = 365; // 日数
constexpr int CN = 26; // コンテストの種類数
int c[CN];             // コンテストの満足度の下がりやすさ
int s[D][CN];          // ある日付にコンテストを開催したときの満足度の増加量

void input()
{
    int _;
    cin >> _;
    for (int i = 0; i < CN; i++)
        cin >> c[i];
    for (int i = 0; i < D; i++)
        for (int j = 0; j < CN; j++)
            cin >> s[i][j];
}

constexpr const long long int INF = 1000000000LL; // あり得ないぐらい大きなスコアの例を用意しておく

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
    long long int actual_score_;    // 実際のスコア
    long long int evaluated_score_; // 探索上で評価したスコア
    int day_;                       // 日付
    vector<int> last_days_;         // 各コンテストを最後に開いた日付
    State()
    {
        actual_score_ = 1e6;
        evaluated_score_ = actual_score_;
        day_ = 0;
        last_days_ = vector<int>(CN, -1);
    }

    // 終了判定
    bool isDone() const
    {
        return this->day_ == D;
    }

    // 指定したactionで状態を1ステップ進め、評価する
    void advance(const int action)
    {
        this->actual_score_ += s[this->day_][action];
        this->last_days_[action] = this->day_;
        for (int i = 0; i < CN; i++)
        {
            this->actual_score_ -= c[i] * (this->day_ - this->last_days_[i]);
        }
        this->evaluated_score_ = this->actual_score_;
        for (int i = 0; i < CN; i++)
        {
            auto check_day = this->day_ + 4;
            if (check_day >= D)
            {
                check_day = D - 1;
            }
            // actual_score_ で既に day_ まで減らしているので、未来分は day_+1 ～ check_day のみ
            auto score_gap = day_cumsum(this->last_days_[i], check_day + 1) - day_cumsum(this->last_days_[i], this->day_ + 1);
            this->evaluated_score_ -= c[i] * score_gap;
        }
        ++this->day_;
    }

    // 現在の状態から探索対象にする操作を取得する
    vector<int> legalActions() const
    {
        vector<int> actions{};
        for (int action = 0; action < CN; action++)
        {
            actions.emplace_back(action);
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
    cerr << "入力読み取り完了" <<endl;
    State state{};
    cerr << "状態初期化完了" <<endl;
    auto actions = greedy(state);
    cerr << "回答生成完了" <<endl;
    output(actions);
    cerr << "出力完了" <<endl;
    return 0;
}