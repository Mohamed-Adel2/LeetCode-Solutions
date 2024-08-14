With cte AS (
    SELECT person_name,
    SUM(weight) OVER (ORDER BY turn) AS w
    FROM Queue
)

SELECT
    person_name
FROM cte
WHERE cte.w IN (SELECT MAX(w) FROM cte WHERE cte.w <= 1000);