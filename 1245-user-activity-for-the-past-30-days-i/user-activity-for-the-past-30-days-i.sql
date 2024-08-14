SELECT 
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users 
FROM Activity
WHERE activity_date between DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
GROUP BY activity_date;