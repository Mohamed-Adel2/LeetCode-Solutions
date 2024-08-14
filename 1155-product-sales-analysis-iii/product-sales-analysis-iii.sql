SELECT 
    product_id,
    year AS first_year,
    quantity,
    price
FROM (
    SELECT *, RANK() over (PARTITION BY product_id ORDER BY year) AS rnk
    FROM Sales
) AS s
WHERE s.rnk = 1;