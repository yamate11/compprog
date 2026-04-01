# AtCoderHeuristic_FirstStep_Vol.2 サンプルコード

## 構成

```bash
.
├── answers 解答例なので見ないでください。
│   ├── cpp
│   └── python
└── samples 今回の演習で使うサンプル
    ├── cpp
    │   ├── sample_greedy.cpp 貪欲法の穴埋め演習用ファイル
    │   └── sample_beam.cpp ビームサーチの穴埋め演習用ファイル
    └── python
        ├── sample_greedy.py 貪欲法の穴埋め演習用ファイル
        └── sample_beam.py ビームサーチの穴埋め演習用ファイル
```

## 使い方

[公式ツール](https://img.atcoder.jp/intro-heuristics/tools.zip?_gl=1*p0gngo*_ga*Njg0MDYzNTgxLjE3MjA4NzI5NDk.*_ga_RC512FD18N*czE3NjE3MTMzMTYkbzY4NiRnMSR0MTc2MTcxMzMyMiRqNTQkbDAkaDA.)をダウンロードし、以下のように配置してください。

```bash
.
├── tools ここ
├── answers 
└── samples
```

samplesのcpp,pythonから好きな方を選び、sample_greedy.cpp or sample_greedy.pyの`TODO`と記載がある部分を埋めてください。

### c++の場合

```bash
# コンパイル
g++ -std=c++20 -O2 samples/cpp/sample_greedy.cpp -o a.out
# 実行
mkdir -p tools/out
./a.out < tools/in/0000.txt > tools/out/greedy.txt
# 評価
cd tools
cargo run -r --bin vis ./in/0000.txt ./out/greedy.txt
```

### pythonの場合

```bash
# 実行
mkdir -p tools/out
python3 samples/python/sample_greedy.py < tools/in/0000.txt > tools/out/greedy.txt
# 評価
cd tools
cargo run -r --bin vis ./in/0000.txt ./out/greedy.txt
```
