(ns depth-first-search)

(defn depth-first-search
  ([graph at visited-nodes]
    (if (get visited-nodes at)
      visited-nodes
      (let
        [visited-nodes (assoc visited-nodes at true)]
        (reduce
          #(depth-first-search graph %2 %1)
          visited-nodes
          (get graph at)))))
          
  ([graph at]
    (depth-first-search graph at (vec (boolean-array (count graph) false)))))


; Playground
(depth-first-search 
   {0 [1 3], 1 [0 2], 2 [1 4], 3 [0 4], 4 [2 3 5 6], 5 [4], 6 [4 7], 7 [6], 8 []}
   0)