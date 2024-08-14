SELECT ROUND(SUM(IF(order_date = customer_pref_delivery_date, 1, 0)) / COUNT(*) * 100, 2) AS immediate_percentage
FROM (
    SELECT *
    FROM Delivery d1
    WHERE order_date = (
        SELECT MIN(order_date)
        FROM Delivery d2
        WHERE d1.customer_id = d2.customer_id
    )
) AS res;