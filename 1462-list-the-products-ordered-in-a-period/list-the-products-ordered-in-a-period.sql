SELECT 
    p.product_name,
    SUM(unit) AS unit
FROM Orders o, Products p
WHERE o.product_id = p.product_id
AND DATE_FORMAT(order_date, '%M %Y') = 'February 2020'
GROUP BY p.product_id
HAVING SUM(unit) >= 100