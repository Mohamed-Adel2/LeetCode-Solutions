WITH cte AS(
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING count(num) = 1
)

SELECT MAX(num) AS num
FROM cte;