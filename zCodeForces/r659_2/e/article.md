title: 
Codeforces Round #659 (Div.2-E / Div.1-C) String Transformation 2

<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    tex2jax: {
      inlineMath: [['$','$'], ['\\(','\\)']],
      displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
    }
  });
</script>
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

## 問題へのリンク

[こちら](https://codeforces.com/contest/1384/problem/E)

## 状況

コンテストでは，そもそも全然届かず解き始めることもできませんでした．
その後解説ACしたのですが，解説があまりよくわからなかったので，
メモを残しておこうという趣旨です．

## 解法

'a' から 't' までの20個のアルファベットをノードとする
自己辺の無い単純有向グラフ
$(N, E)$ を次のように定義する:
$E = \\{ (A_i, B_i) \\mid i = 1, \\ldots, n; A_i \\neq B_i \\}$．
これが連結でないときには連結成分ごとに考えれば良いので，
以下では連結だと仮定する．$|N| = n$ とする．

$S$ を，アルファベットの列 $(p_i)_i$ で，以下の条件を満たすものの集合とする:
すべての $(c,d) \in E$ に対し，$i < j$ が存在して，$p_i = c$, $p_j = d$．

補題: $S$の最も短い要素の長さを $k$ とすると， $k -1$ が求める答となる．

証明: $S$の要素$p_1, \ldots, p_k$ があると，長さ$k -1$ の操作列を作れる．
第$i$回目の操作では，$A$に現れる $p_i$ のうち，まだゴールに達していない
ものを，$p\_{i+1}$ に置き換えれば良い．
逆に，長さ$k$の操作列が与えられたとして，第$i$回目の操作では，文字 $c_i$ を
文字 $d_i$ に置き換えるものとする．
同じ長さの同値な操作で，$d\_{i+1} = c\_{i}$ 
($i = 1, \ldots, k - 1$) となるものが作れることを言えば良い．
隣接する操作列に同じ文字が現れなければ，入れ替えても良い．
グラフは連結としたので，入れ替えていけば，どこかで隣接する操作列に
同じ文字が現れる．

* $(c, e) - (d, e)$ の時には，$(c, d) - (d, e)$ に書き換えられる．
* $(c, d) - (c, e)$ の時には，$(c, d) - (d, e)$ に書き換えられる．
* $(c, d) - (e, c)$ の時には，$(e, c) - (c, d)$ に書き換えられる．

これを繰り返せば良い．(証明終)

補題: グラフの DAG である部分集合の要素数の最大値を $m$ とすると，
$k = 2n - m$ である．

証明: $X$ が DAG であるとき，次のアルファベットの列は，
長さが $2n - |X| $ で，$S$ の要素となる．

* まず $N \\setminus X$ をまず任意の順序で並べ，
* 次に $X$ をトポロジカルオーダで並べ，
* もう一度$N \\setminus X$ を任意の順序で並べる

したがって，$2n - m \geq k$である．逆に，$S$ の要素 $p$ をとる．
連結性より，$N$ の要素はすべて $p$ に現れる．このうち，$p$ に
一回しか現れない要素の集合を $X$ とすれば，$X$ は DAG になる．
したがって，$ |p| \geq |X| + 2 | N \setminus X | = 2n - |X| \geq 2n - m $.
特に $p$ として最小の長さのものを取れば，$ k \geq 2n - m $．(証明終)

2つの補題より，最大サイズのDAGを求めれば良いことがわかった．
DAGは，トポロジカルオーダの順に育てていくことを考えると，
次の方法で列挙することができる:

* DAG $D$ に対して，
  $f(D) 
    := \\{ D \\cup \\{ x \\} \\mid 
        x \\in N \\setminus D,  xE \\cap D = \\varnothing \\} $
  とする．ただし，$xE := \\{ y \\mid (x,y) \\in E \\}$．

* $\\mathcal{D} := \\{\\varnothing\\}$ からスタートし，
  $\\mathcal{D}$ の各要素 $D$ に対して，$f(D)$ の各要素を
  $\\mathcal{D}$ に追加する．追加できなくなるまで繰り返す．

これは，集合の bit 表現と，queue を使って実現できる．
各 $x\in N$ に対する $xE$ を事前計算しておけば，
この部分の計算量は $\mathcal{O}(n\\cdot 2\^n)$ である．

## コード

[こちら](https://codeforces.com/contest/1384/submission/88108884)

## 感想

完全グラフのときには，たとえば，N = {a,b,c,d} として，
a -> b -> c -> d -> c -> b -> a だよなあ．
くらいまでは考えられたのですが，
{d} だけが特別なので，ここを DAG に一般化できる，
というのがおもしろいと感じました．

