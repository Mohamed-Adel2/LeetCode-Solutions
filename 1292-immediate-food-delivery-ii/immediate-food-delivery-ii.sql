SELECT ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM Delivery d1
WHERE order_date = (
    SELECT MIN(order_date)
    FROM Delivery d2
    WHERE d1.customer_id = d2.customer_id
);