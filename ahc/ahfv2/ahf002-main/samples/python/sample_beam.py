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
        self.actions = []

    def is_done(self) -> bool:
        """終了判定"""
        return # TODO: sample_greedy.pyで実装したものをコピペ

    def advance(self, action: int) -> None:
        """指定したactionで状態を1ステップ進め、評価する"""
        # TODO: sample_greedy.pyで実装したものをコピペ

    def legal_actions(self) -> list[int]:
        """現在の状態から探索対象にする操作を取得する"""
        return # TODO: sample_greedy.pyで実装したものをコピペ

    def clone(self) -> "State":
        next_state = State()
        next_state.evaluated_score = self.evaluated_score
        next_state.day = self.day
        next_state.last_days = self.last_days[:]
        next_state.actions = self.actions[:]
        return next_state


def beam_search(state: State, beam_width: int) -> list[int]:
    """ビーム幅を指定してビームサーチで操作列を決定する"""

    now_beam: list[State] = []
    best_state = State()

    now_beam.append(state)
    while True:
        next_beam: list[State] = []
        for now_state in now_beam[: min(beam_width, len(now_beam))]:
            for action in now_state.legal_actions():
                next_state = now_state.clone()
                next_state.advance(action)
                next_state.actions.append(action)
                next_beam.append(next_state)
        next_beam.sort(key=lambda st: st.evaluated_score, reverse=True)
        next_beam = next_beam[: min(beam_width, len(next_beam))]

        now_beam = next_beam
        best_state = now_beam[0]

        if best_state.is_done():
            break
    return best_state.actions


def output_actions(actions: list[int]) -> None:
    for action in actions:
        print(action + 1)


if __name__ == "__main__":
    read_input()

    state = State()
    actions = beam_search(state, 250)
    output_actions(actions)
