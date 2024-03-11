修正とテストの方法:

foo.cc を修正する場合．

* tmp_xxx というような名前のディレクトリを作る．
* foo.cc と test/foo_skel.cc を，tmp_xxx/foo.cc, tmp_xxx/test/foo_skel.cc にコピーする
* Makefile を tmp_xxx/Makefile にコピーする
* test/Makefile を tmp_xxx/test/Makefile にコピーする
* tmp_xxx/foo.cc と tmp_xxx/test/foo_skel.cc を編集する
* tmp_xxx/test で，make foo_t で foo_t を作成し，テストする．
* tmp_xxx/foo.cc と tmp_xxx/test/foo_skel.cc を foo.cc と test/foo_skel.cc にコピーする
* make test で，全体をテストする．

