SELECT contest_id, ROUND(COUNT(contest_id)/(SELECT COUNT(*) FROM USERS)*100 ,2) AS percentage

FROM Users u JOIN Register r
ON u.user_id = r.user_id
GROUP BY contest_id
ORDER BY percentage DESC , contest_id ASC