; https://www.codewars.com/kata/556deca17c58da83c00002db/train/clojure

(defn tribonacci [[a b c :as items] n]
    (reduce
        (fn [list i] (conj list 
            (if (< i 3)
                (get items i)
                (apply + (map #(get list (- i % 1)) (range 3))))))
        []
        (range n))
)

(tribonacci [1 1 1] 10)