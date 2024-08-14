SELECT
    product_id,
    IF(change_date <= '2019-08-16', new_price, 10) AS price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)
OR (product_id, change_date) IN (
    SELECT product_id, MIN(change_date)
    FROM Products
    GROUP BY product_id
    HAVING MIN(change_date) > '2019-08-16'
)
