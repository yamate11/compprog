修正とテストの方法:

foo.cc を修正する場合．

* tmp_xxx というような名前のディレクトリを作る．
* 以下のファイルを tmp_xxx にコピーする:
  * Makefile
  * foo.cc
  * test/Makefile
  * test/foo_skel.cc
  * test/foo_t.d
  * その他，test/foo_t.d でリストされているファイル
* Makefile を tmp_xxx/Makefile にコピーする
* test/Makefile を tmp_xxx/test/Makefile にコピーする
* tmp_xxx/foo.cc と tmp_xxx/test/foo_skel.cc を編集する
* tmp_xxx/test で，make foo_t で foo_t を作成し，テストする．
  * デバッグするときには make DEBUG=yes foo_t
* コピーしたファイルを元に戻す．
* make test で，全体をテストする．

