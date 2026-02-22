#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 最初の到達時刻と、それに対応するのが何本目の電車か
    int first_arrival = 1000000000, first_train_id = 0;

    for (int i = 1; i <= N; ++i) {
        string destination;
        int time;
        cin >> destination >> time;
        // 行き先が高橋駅で、これまでに見た電車より早く着くなら
        if (destination == "Takahashi" && first_arrival > time) {
            // 情報を更新
            first_arrival = time;
            first_train_id = i;
        }
    }

    cout << first_train_id << endl;
    return 0;
}
