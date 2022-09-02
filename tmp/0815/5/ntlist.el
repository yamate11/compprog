(defun foobarbaz ()
  (interactive)
  (save-excursion
    (let* ((start-old (line-beginning-position))
           (spec (buffer-substring start-old (line-end-position)))
           (buf (get-buffer-create "*atcoder-expand*"))
           (save-case-fold-search case-fold-search)
           (rc nil) 
           )
      (with-current-buffer buf (erase-buffer))
      (setq rc (call-process "/home/y-tanabe/proj/compprog/tmp/0815/5/yt" nil buf nil spec))
      (if (= rc 0)
          (let ((expanded (with-current-buffer buf (buffer-substring (point-min) (point-max))))
                (idx (string-match "\\[[A-Za-z0-9]\\{8\\}\\]" spec))
                (end-old nil))
            (if idx
                (progn
                  (setq case-fold-searh nil)
                  (end-of-line)
                  (search-forward (concat "@End " (substring spec idx (+ idx 10))) nil t)
                  (setq case-fold-search save-case-fold-search)))
            (setq end-old (line-beginning-position 2))
            (goto-char start-old)
            (delete-region start-old end-old)
            (insert expanded))
        (message ("expansion failed.  See *atcoder-expand*"))))))
        
                        
                              


(defun func1 ()
  (interactive)
  (save-excursion
    (let* ((spec (buffer-substring (line-beginning-position) (line-end-position)))
           (idx (string-match "\\[[A-Za-z0-9]\\{8\\}\\]" spec)))
      (if idx (message (substring spec (+ idx 1) (+ idx 9)))
        (message "no")))))

    (let ((rc (re-search-forward  (line-end-position) t)))
      (if rc
          (message "found")
        (message "no")))))

abc [01234567]


