SELECT contest_id, ROUND(COUNT(contest_id)/(SELECT COUNT(*) FROM USERS)*100 ,2) AS percentage
FROM Register r
GROUP BY contest_id
ORDER BY percentage DESC , contest_id ASC