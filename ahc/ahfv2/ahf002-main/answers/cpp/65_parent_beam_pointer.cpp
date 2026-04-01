

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
    int action_;                    // この状態に遷移する直前に選んだ操作
    shared_ptr<State> parent_;      // 1つ前の状態へのポインタ
    State()
    {
        evaluated_score_ = 1e6;
        day_ = 0;
        last_days_ = vector<int>(CN, -1);
        action_ = -1;
        parent_ = nullptr;
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

bool operator>(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ > state_2.evaluated_score_;
}

// ビーム幅を指定してビームサーチで操作列を決定する
vector<int> beamSearch(
    const State &state,
    const int beam_width)
{
    vector<shared_ptr<State>> now_beam;
    shared_ptr<State> best_state;

    now_beam.emplace_back(make_shared<State>(state));
    for (int t = 0;; t++)
    {
        vector<shared_ptr<State>> next_beam;
        for (int i = 0; i < (int)now_beam.size(); i++)
        {
            const shared_ptr<State> &now_state = now_beam[i];
            auto legal_actions = now_state->legalActions();
            for (const auto &action : legal_actions)
            {
                auto next_state = make_shared<State>(*now_state);
                next_state->advance(action);
                next_state->action_ = action;
                next_state->parent_ = now_state;
                next_beam.emplace_back(next_state);
            }
        }
        sort(next_beam.begin(), next_beam.end(), [](const shared_ptr<State> &state_1, const shared_ptr<State> &state_2)
             { return *state_1 > *state_2; });
        next_beam.resize(min(beam_width, (int)next_beam.size()));

        now_beam = next_beam;
        best_state = now_beam[0];

        if (best_state->isDone())
        {
            break;
        }
    }

    // 最後の状態から親ポインタを逆に辿って、操作列を復元する
    vector<int> actions;
    while (best_state->parent_ != nullptr)
    {
        actions.emplace_back(best_state->action_);
        best_state = best_state->parent_;
    }
    reverse(actions.begin(), actions.end());
    return actions;
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
    auto actions = beamSearch(state, 250);
    cerr << "回答生成完了" <<endl;
    output(actions);
    cerr << "出力完了" <<endl;
    return 0;
}
