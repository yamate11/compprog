(setq atcoder-library-list
      '("NONE" "cmpNaive" "UnionFind" "bit" "cht" "coordCompr" "debug"
	"dinic" "fix"
	"integer" "matrix" "misc" "mod" "segTree" "sieve" "strSearch"
	"util" "scc" "LinTr" "geometry" "binsearch" "dijkstra" "rerror"
	"suffixArray" "board" "minCostFlow" "perm" "guessPoly" "ftwo"
	"trie" "tree" "rollingHash" "fft" "doubling" "ipoint" "cumsum2d"
	"interactive" "intervalSet" "polynomial" "convolution" "adjMatrix"
        "interpolation" "fastTransform"
	"f:power" "f:<<" "f:>>" "f:updMaxMin" "f:gcd" "f:intDiv" 
        "f:perfmeas" "f:mex" "f:shortVector" "f:floor_sum" "f:itrange"
	))

(setq atcoder-topdir "/home/y-tanabe/proj/compprog")
(setq atcoder-insertion-mark "@@ !! LIM")

(defun atcoder-fn-insert-library (arg)
  (let ((s1 nil) (e1 nil) (rc nil))
    (save-excursion
      (beginning-of-buffer)
      (search-forward atcoder-insertion-mark)
      (setq s1 (line-beginning-position))
      (end-of-buffer)
      (search-backward atcoder-insertion-mark)
      (setq e1 (line-beginning-position 2))
      (setq rc (shell-command-on-region s1 e1
					(concat "libins '" arg "'") 1 t)))
    (if (= rc 0)
	(progn
	  (let ((fpath (concat atcoder-topdir "/clib/" arg ".cc"))
		(sbuf (current-buffer)))
	    (if (file-exists-p fpath)
		(progn
		  (find-file-read-only-other-window fpath)
		  (switch-to-buffer-other-window sbuf))))
	  (message "Successfully inserted."))
      (progn (message "*** libins FAILED.  Consider UNDO.")
	     (goto-char s1)))))
  
(defun atcoder-insert-library (arg)
  "Insert a library file content.
Lines containing the insertion mark, \"@@ !! LIM\", are searched
from the beginning and the end, the surronded text are passed to
command libins, and the result replaces the text.

A space-separated and parentheses-surrounded list following the
insertion mark and in the same line is the list of already
inserted library contents.  Items in the form of \"f:xxx\" are
functions, others are files.

If you just want to update the contents withoug adding new items,
call this function with argument \"NONE\".

For the library file format, consult the help message of command libins."
  (interactive (list (completing-read "Library name: " atcoder-library-list)))
  (atcoder-fn-insert-library arg))

(global-set-key "\e\ei" 'atcoder-insert-library)
