; -- // Code by SoundOfSpouting#6980 (UID: 319753218592866315)

(defun I expr (let-seq
  ; Turn the input into a sequence of tokens.
  (def lex ((str:lexer "[0-9]+" "[\\-+*/]" " *") expr))
  ; Build the AST (coalesce the whitespace around the operator to determine precedence).
  (def ast (append (filter #0 (:(lambda x (match x
    (((2 'x) (1 'y) (2 'x)) (tie y (tally x)))
    (((1 'x) (0 'y) 'z) (tie x 0))
    (((0 'x) 'y 'z) (tie (parse-number x)))
    ('_ 'nil))) (windows 3 lex))) (tie@tie@parse-number@car@cdar@reverse lex)))
  ; Perform one step of graph reduction on the AST.
  (defun step ast (let-seq
    ; Single constant: Nothing to do.
    (case (= 1 (tally ast)) ast)
    ; Find the leftmost operator with lowest precedence.
    (def wnd (* 2 (+ 1 ([car@index-of tie@$(foldl1 min) #0] (:cadr (filter [= 2 tally] ast))))))
    ; Evaluate the binary expression and adjoin the change to the AST.
    (def op (hashmap:get %{ "/" => /, "+" => +, "-" => -, "*" => * } ast$[- wnd 1].0))
    (foldl1 append (tie (take (- wnd 2) ast) (tie@tie (lift op (:car ast$[- wnd '(2 0)]))) (drop (+ wnd 1) ast)))))
  ; Converge the graph reduction step.
  (caar@converge step ast)))
