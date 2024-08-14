WITH cte AS (
    SELECT
        name,
        COUNT(*) AS cnt
    FROM MovieRating m, Users u
    WHERE m.user_id = u.user_id
    GROUP BY u.user_id
    ORDER BY cnt DESC, name ASC
    LIMIT 1
),
cte2 AS(
    SELECT
        title,
        AVG(rating) AS average
    FROM MovieRating m, Movies mv
    WHERE m.movie_id = mv.movie_id
    AND DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
    GROUP BY mv.movie_id
    ORDER BY average DESC, title ASC
    LIMIT 1    
)

SELECT
    name AS results
FROM cte

UNION ALL

SELECT
    title AS results
FROM cte2