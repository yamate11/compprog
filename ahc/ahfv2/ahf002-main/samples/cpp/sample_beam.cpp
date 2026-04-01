

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

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
    long long int real_score_;
    int day_;                       // 日付
    vector<int> last_days_;         // 各コンテストを最後に開いた日付
    vector<int> actions_;           // 操作の履歴
    State()
    {
        evaluated_score_ = 1e6;
        day_ = 0;
        last_days_ = vector<int>(CN, -1);
        actions_ = vector<int>();
    }

    // 終了判定
    bool isDone() const
    {
      return day_ == D;
    }

    // 指定したactionで状態を1ステップ進め、評価する
    void advance(const int action)
    {
#if 0
      ll diff = 0;
      for (int i = 0; i < 26; i++) {
        if (i == action) diff += s[day_][i];
        else diff -= (day_ - last_days_[i]) * c[i];
      }
      evaluated_score_ += diff;
      last_days_[action] = day_;
      day_ ++;
        /* TODO: sample_greedy.cppで実装したものをコピペ */
#else

    ll diff = 0;
    for (int i = 0; i < 26; i++) {
      if (i == action) diff += s[day_][i];
      else diff -= (day_ - last_days_[i]) * c[i];
    }
    real_score_ += diff;
    last_days_[action] = day_;
    
    evaluated_score_ = real_score_;

    ll mysum1 = 0;
    ll mysum2 = 0;
    for (int i = 0; i < 26; i++) {
      mysum1 += last_days_[i] * c[i];
      mysum2 += c[i];
    }

    ll dir = 5 * (D - day_) / D;
    ll lim = min((ll)D, (ll)(day_ + dir));
    for (int d = day_ + 1; d < lim; d++) {
      evaluated_score_ += mysum1 - mysum2 * d;
    }
    cerr << "day_ = " << day_ << " " << real_score_ << " " << evaluated_score_ << endl;

    day_ ++;

#endif

    }

    // 現在の状態から探索対象にする操作を取得する
    vector<int> legalActions() const
    {
      ll sz1 = 6;
      ll sz2 = 6;

      vector<pll> vec1(26);
      for (int i = 0; i < 26; i++) vec1[i] = pll(s[day_][i], i);
      sort(vec1.begin(), vec1.end(), greater<pll>());

      vector<pll> vec2(26);
      for (int i = 0; i < 26; i++) vec2[i] = pll(c[i] * (day_ - last_days_[i]), i);
      sort(vec2.begin(), vec2.end(), greater<pll>());

      vector<int> ret;
      for (int i = 0; i < sz1; i++) ret.push_back(vec1[i].second);
      for (int i = 0; i < sz1; i++) ret.push_back(vec2[i].second);
      sort(ret.begin(), ret.end());
      ret.erase(unique(ret.begin(), ret.end()), ret.end());

      return ret;
      
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
    cerr << "入力読み取り完了" <<endl;
    State state{};
    cerr << "状態初期化完了" <<endl;
    auto actions = beamSearch(state, 120);
    cerr << "回答生成完了" <<endl;
    output(actions);
    cerr << "出力完了" <<endl;
    return 0;
}
