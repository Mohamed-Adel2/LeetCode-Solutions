WITH cte AS(
    SELECT customer_id, COUNT(distinct product_key) AS cnt
    FROM Customer
    GROUP BY customer_id 
)
SELECT
    customer_id
FROM cte
WHERE cnt IN (SELECT count(*) FROM Product)