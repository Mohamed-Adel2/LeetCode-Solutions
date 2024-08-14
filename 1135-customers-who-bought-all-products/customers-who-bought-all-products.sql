SELECT
    customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(distinct product_key) IN (SELECT COUNT(*) FROM Product);