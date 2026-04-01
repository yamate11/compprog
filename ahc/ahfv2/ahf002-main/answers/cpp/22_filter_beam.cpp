

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int D = 365;      // 日数
constexpr int CN = 26;      // コンテストの種類数
int c[CN];                  // コンテストの満足度の下がりやすさ
array<array<int, CN>, D> s; // ある日付にコンテストを開催したときの満足度の増加量
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

struct State
{
    long long int actual_score_;    // 実際のスコア
    long long int evaluated_score_; // 探索上で評価したスコア
    int day_;                       // 日付
    vector<int> last_days_;         // 各コンテストを最後に開いた日付
    vector<int> actions_;           // 操作の履歴
    State()
    {
        actual_score_ = 1e6;
        evaluated_score_ = actual_score_;
        day_ = 0;
        last_days_ = vector<int>(CN, -1);
        actions_ = vector<int>();
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
        ++this->day_;
    }

    // 現在の状態から探索対象にする操作を取得する
    vector<int> legalActions() const
    {
        vector<int> actions{};
        auto thresholed = s_contests[this->day_][0].first * 0.3;
        for (int action = 0; action < CN / 2; action++)
        {
            const auto &[score, contest] = s_contests[this->day_][action];
            if (score < thresholed)
            {
                break;
            }
            actions.emplace_back(contest);
        }
        return actions;
    }
};

bool operator>(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ > state_2.evaluated_score_;
}

// ビーム幅を指定してビームサーチで操作列を決定する
vector<int> beamSearch(
    const State &state,
    const int beam_width)
{
    vector<State> now_beam;
    State best_state;

    now_beam.emplace_back(state);
    for (int t = 0;; t++)
    {
        vector<State> next_beam;
        for (const State& now_state : now_beam)
        {
            auto legal_actions = now_state.legalActions();
            for (const auto &action : legal_actions)
            {
                State next_state = now_state;
                next_state.advance(action);
                next_state.actions_.emplace_back(action);
                next_beam.emplace_back(next_state);
            }
        }
        sort(next_beam.begin(), next_beam.end(), greater<State>());
        next_beam.resize(min(beam_width, (int)next_beam.size()));

        now_beam = next_beam;
        best_state = now_beam[0];

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
    cerr << "プログラム開始" <<endl;
    input();
    preprocess();
    cerr << "入力読み取り完了" <<endl;
    State state{};
    cerr << "状態初期化完了" <<endl;
    auto actions = beamSearch(state, 250);
    cerr << "回答生成完了" <<endl;
    output(actions);
    cerr << "出力完了" <<endl;
    return 0;
}