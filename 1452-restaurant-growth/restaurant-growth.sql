WITH cte AS(
    SELECT 
        SUM(amount) OVER(ORDER BY visited_on) AS cum_sum,
        DENSE_RANK() over(ORDER BY visited_on) AS rnk,
        visited_on
    FROM Customer
    ORDER BY visited_on
)

SELECT
    DISTINCT visited_on,
    CASE
        WHEN c1.rnk = 7 THEN cum_sum
        ELSE cum_sum - (SELECT cum_sum FROM cte c2 WHERE c2.rnk = c1.rnk - 7 LIMIT 1)
    END AS amount,
    CASE
        WHEN c1.rnk = 7 THEN ROUND(cum_sum / 7, 2)
        ELSE ROUND((cum_sum - (SELECT cum_sum FROM cte c2 WHERE c2.rnk = c1.rnk - 7 LIMIT 1)) / 7, 2)
    END AS average_amount
FROM cte c1
WHERE c1.rnk > 6
ORDER BY c1.visited_on;