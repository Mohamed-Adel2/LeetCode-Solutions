SELECT q.query_name,
       ROUND(AVG(q.rating / q.position), 2) AS quality,
       ROUND((SELECT COUNT(*) FROM Queries q2 WHERE q2.rating < 3 AND q2.query_name = q.query_name) / COUNT(q.query_name) * 100, 2) AS poor_query_percentage
FROM Queries q
WHERE q.query_name IS NOT NULL
GROUP BY q.query_name;