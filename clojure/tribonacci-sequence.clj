; https://www.codewars.com/kata/556deca17c58da83c00002db/train/clojure

(defn tribonacci [[a b c] n]
    (reduce #(conj % %2) [] (range n))
)

(range 0)

(tribonacci [1 1 1] 10)