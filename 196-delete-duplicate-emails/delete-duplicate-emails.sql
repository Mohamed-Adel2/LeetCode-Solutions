DELETE FROM Person
WHERE (id, email) NOT IN(
    SELECT id, email
    FROM (
        SELECT min(id) AS id, email
        FROM Person
        GROUP BY email
    ) AS x
)