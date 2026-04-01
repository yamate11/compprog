

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

struct State
{
    long long int evaluated_score_; // 探索上で評価したスコア
    int day_;                       // 日付
    vector<int> last_days_;         // 各コンテストを最後に開いた日付
    State()
    {
        evaluated_score_ = 1e6;
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
        this->evaluated_score_ += s[this->day_][action];
        this->last_days_[action] = this->day_;
        for (int i = 0; i < CN; i++)
        {
            this->evaluated_score_ -= c[i] * (this->day_ - this->last_days_[i]);
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