#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
from matplotlib.patches import Circle

# 入力ファイル名と出力ファイル名
INFILE = "data.txt"
OUTFILE = "circles.png"

# 座標範囲（問題文どおり）
X_MIN, X_MAX = 0, 1500
Y_MIN, Y_MAX = 0, 1500

def read_data(path: str):
    circles = []
    with open(path, "r", encoding="utf-8") as f:
        for lineno, line in enumerate(f, 1):
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split()
            if len(parts) != 3:
                raise ValueError(f"{path}:{lineno}: 3整数 x y r を期待しました: {line!r}")
            x, y, r = map(int, parts)

            # 軽いバリデーション（不要なら削ってOK）
            if not (X_MIN <= x <= X_MAX and Y_MIN <= y <= Y_MAX and 1 <= r <= 100):
                raise ValueError(f"{path}:{lineno}: 範囲外データ: x={x}, y={y}, r={r}")

            circles.append((x, y, r))
    return circles

def main():
    circles = read_data(INFILE)

    fig, ax = plt.subplots(figsize=(8, 8), dpi=200)

    # 円を追加（塗りつぶし無し，輪郭のみ）
    for x, y, r in circles:
        ax.add_patch(Circle((x, y), r, fill=False, linewidth=1, alpha=0.7))

    # 軸設定
    ax.set_xlim(X_MIN, X_MAX)
    ax.set_ylim(Y_MIN, Y_MAX)
    ax.set_aspect("equal", adjustable="box")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.grid(True, linewidth=0.5, alpha=0.4)

    ax.set_title(f"{len(circles)} circles (center=(x,y), radius=r)")

    plt.tight_layout()
    fig.savefig(OUTFILE, bbox_inches="tight")
    plt.close(fig)

    print(f"Saved: {OUTFILE}")

if __name__ == "__main__":
    main()
