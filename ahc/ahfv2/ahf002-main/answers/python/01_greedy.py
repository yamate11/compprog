import sys

D = 365  # 日数
CN = 26  # コンテストの種類数
c = [0] * CN  # コンテストの満足度の下がりやすさ
s = [[0] * CN for _ in range(D)]  # ある日付にコンテストを開催したときの満足度の増加量


def read_input() -> None:
    _ = int(input())
    c[:] = list(map(int, input().split()))
    for i in range(D):
        s[i] = list(map(int, input().split()))


INF = 1_000_000_000  # あり得ないぐらい大きなスコアの例を用意しておく


class State:
    def __init__(self) -> None:
        self.evaluated_score = 1_000_000
        self.day = 0
        self.last_days = [-1] * CN

    def is_done(self) -> bool:
        return self.day == D

    def advance(self, action: int) -> None:
        self.evaluated_score += s[self.day][action]
        self.last_days[action] = self.day
        for i in range(CN):
            self.evaluated_score -= c[i] * (self.day - self.last_days[i])
        self.day += 1

    def legal_actions(self) -> list[int]:
        return list(range(CN))

    def clone(self) -> "State":
        next_state = State()
        next_state.evaluated_score = self.evaluated_score
        next_state.day = self.day
        next_state.last_days = self.last_days[:]
        return next_state


def greedy(state: State) -> list[int]:
    """貪欲法で操作列を決定する"""

    best_actions: list[int] = []
    now_state = state
    while not now_state.is_done():
        best_score = -INF  # 絶対にありえない小さな値でベストスコアを初期化する
        best_action = -1  # ありえない操作で初期化する
        for action in now_state.legal_actions():
            next_state = now_state.clone()
            next_state.advance(action)
            if next_state.evaluated_score > best_score:
                best_score = next_state.evaluated_score
                best_action = action
        best_actions.append(best_action)
        now_state.advance(best_action)
    return best_actions


def output_actions(actions: list[int]) -> None:
    out_lines = [str(action + 1) for action in actions]
    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    read_input()
    state = State()
    actions = greedy(state)
    output_actions(actions)
