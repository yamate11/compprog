#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using pll = pair<ll, ll>;

constexpr int D = 365; // 日数
constexpr int CN = 26; // コンテストの種類数
int c[CN];             // コンテストの満足度の下がりやすさ
int s[D][CN];          // ある日付にコンテストを開催したときの満足度の増加量
long long int tot_minus_init = 0;

void input()
{
  int _;
  cin >> _;
  for (int i = 0; i < CN; i++) {
    cin >> c[i];
    tot_minus_init += c[i];
  }
  for (int i = 0; i < D; i++)
    for (int j = 0; j < CN; j++)
      cin >> s[i][j];
}

constexpr const long long int INF = (ll)1e18;

struct State {

  long long int evaluated_score_;               // 探索上で評価したスコア
  long long int acc_score_;                  // 
  int day_;                                        // 日付
  vector<int> last_days_;        // 各コンテストを最後に開いた日付
  long long int tot_minus_;
  vector<int> actions_;                                // 操作の履歴
  State() : evaluated_score_(-INF), acc_score_((ll)1e6), day_(0),
            last_days_(CN, -1), tot_minus_(tot_minus_init), actions_{} {}

  // 明示的に定義していないので，{コピー|ムーブ}{コンストラクタ|代入} は自然に定義される．

  // 終了判定
  bool done() const { return day_ == D; }

  void self_advance(int action) {
    if (action < 0) {
      acc_score -= tot_minus;
      tot_minus += tot_minus_init;
    }else {
      ll recov = c[action] * (day_ - last_days_[action]);
      acc_score_ += s[day_][i] - (tot_minus - recov);
      tot_minus_ += -recov + tot_minus_init 
      last_days_[action] = day_;
    }

    actions_.push_back(action);
    day_++;
  };

  // 指定したactionで状態を1ステップ進める
  State advance(int action) const {
    State ret{*this};
    ret.self_advance(action);
    return ret;
  }

  // 評価値を返す
  long long int eval() {
    ll adv = 4;
    if (evaluated_score_ == -INF) {
      State s{*this};
      ll len = min((int)(D - day_), adv);
      for (int i = 0; i < len; i++) s.self_advance(-1);
      evaluated_score_ = s.acc_score_;
    }
    return evaluated_score_;
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

// ビーム幅を指定してビームサーチで操作列を決定する
vector<int> beamSearch(const State& init_state, const int beam_width) {
  vector<State> beam{init_state};
  for (int t = 0; not beam[0].done(); t++) {
    auto prev_beam = move(beam);
    beam = vector<State>();
    for (const auto& state : prev_beam) {
      for (const auto &action : state.legalActions()) {
        next_beam.push_back(state.advance(action));
      }
    }
    sort(beam.begin(), beam.end(), [](const State& s1, const State& s2) { return s1.eval() > s2.eval(); });
    beam.resize(min(beam_width, (int)beam.size()));
  }
  retun beam[0].actions_;
}

void output(const vector<int> &actions) {
  for (const auto action : actions) cout << action + 1 << endl;
}

int main()
{
  input();
  State state{};
  auto actions = beamSearch(state, 120);
  output(actions);
  return 0;
}
