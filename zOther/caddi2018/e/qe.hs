<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>E: Negative Doubling
 - CADDi 2018 | AtCoder</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="
">
    <meta name="keyword" content="AtCoder,アットコーダー,あっとこーだー,プログラミングコンテスト
">
    <meta name="author" content="Atcoder" />
    <meta name="copyright" content="Copyright (C) 2012 Atcoder" />
    <meta name="format-detection" content="telephone=no" />

    <link rel="stylesheet" type="text/css" href="/css/all.css?v=2">
    <link rel="stylesheet" type="text/css" href="/css/print.css?v=1" media="print">
        <!--[if lt IE 9]>
      <script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->

    <script src="/js/jquery.js"></script>
    <link rel="shortcut icon" href="/img/favicon.ico">

    <script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-30554866-3']);
  _gaq.push(['_setDomainName', 'atcoder.jp']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>    
    <!--[if lt IE 9]><style>.navbar-fixed-top{ position: relative!important; }</style><![endif]-->

  </head>


  <body>
            <style type="text/css">
          .insert-participant-box {
    background-color: #fff !important;
    text-align: -webkit-center !important;
}

.insert-participant-box h1{
    font-size: 280%;
}

#caddi_logo {
    width: 300px;
}

#contest-statement section ul li {
    font-size: 13px;
}

p {
    font-size: 13px;
}
      </style>
          <div class="navbar navbar-fixed-top">
  <div class="navbar-inner">
    <div class="container">
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>
              <a class="brand" href="/"><span class="contest-name">CADDi 2018</span><span class="bland-small"><time>2018/12/22 12:00:00 +0000</time> ~ <time>2018/12/22 14:00:00 +0000</time></span></a>
      
      <div class="nav-collapse">
                            <ul  id="nav-right-logined" class="nav pull-right" style="display:none;">
            <li class="dropdown">
              <a href="#" lang="ja" class="dropdown-toggle static-nav-language-selector-dropdown" data-toggle="dropdown" style="display:none;">
                <i class="flag-ja"></i> 日本語 <b class="caret"></b>
              </a>
              <a href="#" lang="en" class="dropdown-toggle static-nav-language-selector-dropdown"  data-toggle="dropdown" style="display:none;">
                <i class="flag-en"></i> English <b class="caret"></b>
              </a>
              <a href="#" lang="ko" class="dropdown-toggle static-nav-language-selector-dropdown"  data-toggle="dropdown" style="display:none;">
                <i class="flag-ko"></i> 한국어 <b class="caret"></b>
              </a>
              <ul class="dropdown-menu">
                <li> <a lang="ja" class="static-nav-language-selector" href="#"><i class="flag-ja"></i> 日本語</a></li>
                <li> <a lang="en" class="static-nav-language-selector" href="#"><i class="flag-en"></i> English</a></li>
                <li> <a lang="ko" class="static-nav-language-selector" href="#"><i class="flag-ko"></i> 한국어</a></li>
              </ul>
            </li>
            <li class="divider-vertical"></li>
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-cog icon-white"></i> <span id="nav-right-username"></span><b class="caret"></b></a>
              <ul class="dropdown-menu">
                <li><a href="/me"><span class="lang"><span class="lang-en">My Profile</span><span class="lang-ja">マイプロフィール</span></span></a></li>
                                	<li><a href="/settings"><span class="lang"><span class="lang-en">Settings</span><span class="lang-ja">設定</span></span></a></li>
                    <li><a href="/settings/password"><span class="lang"><span class="lang-en">Change password</span><span class="lang-ja">パスワードの変更</span></span></a></li>
                	                		<li><a href="/settings/participants"><span class="lang"><span class="lang-en">Edit information</span><span class="lang-ja">参加登録情報設定</span></span></a></li>
                	                	<li class="divider"></li>
                                <li><a href="/logout"><span class="lang"><span class="lang-en">Sign out</span><span class="lang-ja">ログアウト</span></span></a></li>
             </ul>
            </li>
          </ul>
          <ul id="nav-right-not-login" class="nav pull-right" style="display:none;">
            <li class="dropdown">
              <a href="#" lang="ja" class="dropdown-toggle static-nav-language-selector-dropdown" data-toggle="dropdown" style="display:none;">
                <i class="flag-ja"></i> 日本語 <b class="caret"></b>
              </a>
              <a href="#" lang="en" class="dropdown-toggle static-nav-language-selector-dropdown"  data-toggle="dropdown" style="display:none;">
                <i class="flag-en"></i> English <b class="caret"></b>
              </a>
              <a href="#" lang="ko" class="dropdown-toggle static-nav-language-selector-dropdown"  data-toggle="dropdown" style="display:none;">
                <i class="flag-ko"></i> 한국어 <b class="caret"></b>
              </a>
              <ul class="dropdown-menu">
                <li> <a lang="ja" class="static-nav-language-selector" href="#"><i class="flag-ja"></i> 日本語</a></li>
                <li> <a lang="en" class="static-nav-language-selector" href="#"><i class="flag-en"></i> English</a></li>
                <li> <a lang="ko" class="static-nav-language-selector" href="#"><i class="flag-ko"></i> 한국어</a></li>
              </ul>
            </li>
                        <li class="divider-vertical"></li>
            <li><a href="/register"><span class="lang"><span class="lang-en">Sign up</span><span class="lang-ja">新規登録</span></span></a></li>
                        <li class="divider-vertical"></li>
            <li><a href="/login"><span class="lang"><span class="lang-en">Sign in</span><span class="lang-ja">ログイン</span></span></a></li>
          </ul>
      </div>
    </div>
  </div>
</div>
    <div class="modal hide fade" style="display:none;" id="modal-contest-end">
  <div class="modal-header">
    <a class="close" data-dismiss="modal">×</a>
    <h3><span class="lang"><span class="lang-en">CADDi 2018 has ended</span><span class="lang-ja">CADDi 2018が終了しました</span></span></h3>
  </div>
  <div class="modal-body">
    <p><span class="lang"><span class="lang-en">Contest has ended</span><span class="lang-ja">コンテスト終了です</span></span></p>
  </div>
  <div class="modal-footer">
    <a href="#" class="btn" data-dismiss="modal"><span class="lang"><span class="lang-en">Close</span><span class="lang-ja">閉じる</span></span></a>
  </div>
</div>

<div class="modal hide fade" style="display:none;" id="modal-contest-begin">
  <div class="modal-header">
    <a class="close" data-dismiss="modal">×</a>
    <h3><span class="lang"><span class="lang-en">CADDi 2018 is now opening</span><span class="lang-ja">CADDi 2018の開催時間になりました</span></span></h3>
  </div>
  <div class="modal-body">
    <p><span class="lang"><span class="lang-en">Contest has started</span><span class="lang-ja">問題一覧のページへ移動してください</span></span></p>
  </div>
  <div class="modal-footer">
    <a href="/assignments" class="btn btn-primary"><span class="lang"><span class="lang-en">Go to the task list page</span><span class="lang-ja">問題一覧のページへ移動</span></span></a>
  </div>
</div>
    
    <div id="outer-inner" class="container">
      <h1 class="site-title">
          CADDi 2018
      </h1>
                      <time style="display:none" id="contest-start-time">2018/12/22 12:00:00 +0000</time>
        <time style="display:none" id="contest-end-time">2018/12/22 14:00:00 +0000</time>
        <time style="display:none" id="server-current-time">2018/12/23 02:04:18 +0000</time>

            
      <ul class="nav nav-tabs">
                            <li><a href="https://caddi2018.contest.atcoder.jp/"><i class="icon-home"></i> <span class="lang"><span class="lang-en">Home</span><span class="lang-ja">トップページ</span><span class="lang-ko">톱 페이지</span></span></a></li>
                                          <li class="active"><a href="https://caddi2018.contest.atcoder.jp/assignments"><i class="icon-list-alt"></i> <span class="lang"><span class="lang-en">Tasks</span><span class="lang-ja">問題</span><span class="lang-ko">문제</span></span></a></li>
                                          <li><a href="https://caddi2018.contest.atcoder.jp/submit"><i class="icon-upload"></i> <span class="lang"><span class="lang-en">Submit</span><span class="lang-ja">提出</span><span class="lang-ko">제출</span></span></a></li>
                                          <li><a href="https://caddi2018.contest.atcoder.jp/clarifications"><i class="icon-question-sign"></i> <span class="lang"><span class="lang-en">Clarifications</span><span class="lang-ja">質問</span><span class="lang-ko">질문</span></span></a></li>
                                          <li class="dropdown">
            <a class="dropdown-toggle" data-toggle="dropdown" href="#">
              <b class="caret"></b><i class="icon-download-alt"></i> <span class="lang"><span class="lang-en">Results</span><span class="lang-ja">結果</span><span class="lang-ko">채점 결과</span></span>
            </a>
            <ul class="dropdown-menu">
                              <li><a href="https://caddi2018.contest.atcoder.jp/submissions/all"><span class="lang"><span class="lang-en">All submissions</span><span class="lang-ja">すべての結果</span><span class="lang-ko">모든 결과</span></span></a></li>
                              <li><a href="https://caddi2018.contest.atcoder.jp/submissions/me"><span class="lang"><span class="lang-en">My submissions</span><span class="lang-ja">自分の結果</span><span class="lang-ko">자신의 결과</span></span></a></li>
                          </ul>
          </li>
                                          <li><a href="/standings"><i class="icon-user"></i> <span class="lang"><span class="lang-en">Standings</span><span class="lang-ja">順位表</span><span class="lang-ko">순위표</span></span></a></li>
                                          <li><a href="/custom_test"><i class="icon-user"></i> <span class="lang"><span class="lang-en">Custom Test</span><span class="lang-ja">コードテスト</span></span></a></li>
                                          <li><a href="/editorial"><i class="icon-user"></i> <span class="lang"><span class="lang-en">Editorial</span><span class="lang-ja">解説</span></span></a></li>
                      </ul>
        <div id="alert_box" class="alert alert-block" style="display:none">
  <a class="close" data-dismiss="alert">×</a>
  <h4 id="alert_box_heading" class="alert-heading" style="display:none"></h4>
  <p id="alert_box_content"></p>
</div>

      <h2>E - Negative Doubling</h2>
<hr />
<p><span class="lang"><span class="lang-en">Time limit</span><span class="lang-ja">時間制限</span></span> : 2sec / <span class="lang"><span class="lang-en">Memory limit</span><span class="lang-ja">メモリ制限</span></span> : 1024MB</p>

<div id="task-statement">
  <span class="lang">
<span class="lang-ja">
<p>配点 : <var>800</var> 点</p>

<div class="part">
<section>
<h3>問題文</h3><p><var>N</var> 個の正の整数 <var>A_1, A_2, ..., A_N</var> があります．
高橋君は，これらの整数に対して，次の操作を好きな回数行うことができます：</p>
<ul>
<li><var>1 \leq i \leq N</var> を選び，<var>A_i</var> の値を <var>-2</var> 倍にする．</li>
</ul>
<p><strong>マイナス</strong> <var>2</var> 倍であることに注意してください．</p>
<p>高橋君は，<var>A_1 \leq A_2 \leq ... \leq A_N</var> が成り立つようにしたいです．
このために必要な操作の回数の最小値を求めてください．ただし，不可能な場合は <code>-1</code> を出力してください．</p>
</section>
</div>

<div class="part">
<section>
<h3>制約</h3><ul>
<li><var>1 \leq N \leq 200000</var></li>
<li><var>1 \leq A_i \leq 10^9</var></li>
</ul>
</section>
</div>

<hr />

<div class="io-style">
<div class="part">
<section>
<h3>入力</h3><p>入力は以下の形式で標準入力から与えられる．</p>
<pre><var>N</var>
<var>A_1</var> <var>A_2</var> <var>...</var> <var>A_N</var>
</pre>

</section>
</div>

<div class="part">
<section>
<h3>出力</h3><p>答えを出力せよ．</p>
</section>
</div>
</div>

<hr />

<div class="part">
<section>
<h3>入力例 1</h3><pre>4
3 1 4 1
</pre>

</section>
</div>

<div class="part">
<section>
<h3>出力例 1</h3><pre>3
</pre>

<p>例えば，次のようにすればよいです．</p>
<ul>
<li><var>i=4</var> を選び，<var>A_4</var> の値を <var>-2</var> 倍にする．<var>A_1, A_2, A_3, A_4</var> はそれぞれ <var>3, 1, 4, -2</var> になる．</li>
<li><var>i=1</var> を選び，<var>A_1</var> の値を <var>-2</var> 倍にする．<var>A_1, A_2, A_3, A_4</var> はそれぞれ <var>-6, 1, 4, -2</var> になる．</li>
<li><var>i=4</var> を選び，<var>A_4</var> の値を <var>-2</var> 倍にする．<var>A_1, A_2, A_3, A_4</var> はそれぞれ <var>-6, 1, 4, 4</var> になる．</li>
</ul>
</section>
</div>

<hr />

<div class="part">
<section>
<h3>入力例 2</h3><pre>5
1 2 3 4 5
</pre>

</section>
</div>

<div class="part">
<section>
<h3>出力例 2</h3><pre>0
</pre>

<p>操作を一切せずとも <var>A_1 \leq A_2 \leq ... \leq A_N</var> が成り立っています．</p>
</section>
</div>

<hr />

<div class="part">
<section>
<h3>入力例 3</h3><pre>8
657312726 129662684 181537270 324043958 468214806 916875077 825989291 319670097
</pre>

</section>
</div>

<div class="part">
<section>
<h3>出力例 3</h3><pre>7
</pre></section>
</div>
</span>
<span class="lang-en">
<p>Score : <var>800</var> points</p>

<div class="part">
<section>
<h3>Problem Statement</h3><p>There are <var>N</var> positive integers <var>A_1, A_2, ..., A_N</var>.
Takahashi can perform the following operation on these integers any number of times:</p>
<ul>
<li>Choose <var>1 \leq i \leq N</var> and multiply the value of <var>A_i</var> by <var>-2</var>.</li>
</ul>
<p>Notice that he multiplies it by <strong>minus</strong> two.</p>
<p>He would like to make <var>A_1 \leq A_2 \leq ... \leq A_N</var> holds.
Find the minimum number of operations required. If it is impossible, print <code>-1</code>.</p>
</section>
</div>

<div class="part">
<section>
<h3>Constraints</h3><ul>
<li><var>1 \leq N \leq 200000</var></li>
<li><var>1 \leq A_i \leq 10^9</var></li>
</ul>
</section>
</div>

<hr />

<div class="io-style">
<div class="part">
<section>
<h3>Input</h3><p>Input is given from Standard Input in the following format:</p>
<pre><var>N</var>
<var>A_1</var> <var>A_2</var> <var>...</var> <var>A_N</var>
</pre>

</section>
</div>

<div class="part">
<section>
<h3>Output</h3><p>Print the answer.</p>
</section>
</div>
</div>

<hr />

<div class="part">
<section>
<h3>Sample Input 1</h3><pre>4
3 1 4 1
</pre>

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 1</h3><pre>3
</pre>

<p>One possible solution is:</p>
<ul>
<li>Choose <var>i=4</var> and multiply the value of <var>A_4</var> by <var>-2</var>. <var>A_1, A_2, A_3, A_4</var> are now <var>3, 1, 4, -2</var>.</li>
<li>Choose <var>i=1</var> and multiply the value of <var>A_1</var> by <var>-2</var>. <var>A_1, A_2, A_3, A_4</var> are now <var>-6, 1, 4, -2</var>.</li>
<li>Choose <var>i=4</var> and multiply the value of <var>A_4</var> by <var>-2</var>. <var>A_1, A_2, A_3, A_4</var> are now <var>-6, 1, 4, 4</var>.</li>
</ul>
</section>
</div>

<hr />

<div class="part">
<section>
<h3>Sample Input 2</h3><pre>5
1 2 3 4 5
</pre>

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 2</h3><pre>0
</pre>

<p><var>A_1 \leq A_2 \leq ... \leq A_N</var> holds before any operation is performed.</p>
</section>
</div>

<hr />

<div class="part">
<section>
<h3>Sample Input 3</h3><pre>8
657312726 129662684 181537270 324043958 468214806 916875077 825989291 319670097
</pre>

</section>
</div>

<div class="part">
<section>
<h3>Sample Output 3</h3><pre>7
</pre></section>
</div>
</span>
</span>

</div>


<hr/>
<p><a class="btn btn-primary btn-large" href="/submit?task_id=4560"><span class="lang"><span class="lang-en">Submit</span><span class="lang-ja">提出する</span></span></a></p>

<script>$(function(){document.queryCommandSupported("copy")&&($("h3+pre").before('<div class="div-sample-copy"><span class="btn-sample-copy" tabindex="0" data-toggle="tooltip" data-trigger="manual" title="Copied!">Copy</span></div>'),$(".btn-sample-copy").click(function(){window.getSelection().removeAllRanges();try{var e=document.createRange();e.selectNode($(this).parent().next("pre").get()[0]),window.getSelection().addRange(e),document.execCommand("copy"),$(this).tooltip("show");var t=this;setTimeout(function(){$(t).tooltip("hide")},800)}catch(o){console.log(o)}window.getSelection().removeAllRanges()}))});</script>

    </div>

    <footer>
      <ul>
  <li><a href="/personal"><span class="lang"><span class="lang-en">Personal Information</span><span class="lang-ja">個人情報保護方針</span></span></a></li>
  <li><a href="/tutorial"><span class="lang"><span class="lang-en">Tutorial</span><span class="lang-ja">チュートリアル</span></span></a></li>
  <li><a href="/rules"><span class="lang"><span class="lang-en">Rules</span><span class="lang-ja">ルール</span></span></a></li>
  <li><a href="/glossary"><span class="lang"><span class="lang-en">Glossary</span><span class="lang-ja">用語集</span></span></a></li>
  <li><a href="/faq"><span class="lang"><span class="lang-en">FAQ</span><span class="lang-ja">よくある質問</span></span></a></li>
</ul>
<p id="copyright">Powered by <a href="http://atcoder.jp">AtCoder.</a></p>
    </footer>

    <p id="fixed-server-timer" style="display: none;"></p>

        <script src="/js/bootstrap.min.js"></script>
    <script src="/js/prettify.js"></script>
    <script src="/js/lang-vb.js"></script>
    <script src="/js/lang-hs.js"></script>
    <script src="/js/varmath.js"></script>
    <script src="/js/script.js?v=2"></script>
  </body>
</html>
