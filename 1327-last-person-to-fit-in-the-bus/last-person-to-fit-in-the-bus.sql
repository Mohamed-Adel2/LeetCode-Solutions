With cte AS (
    SELECT 
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn) AS w
    FROM Queue
)

SELECT
    person_name
FROM cte
WHERE cte.w <= 1000
ORDER BY turn DESC
LIMIT 1;