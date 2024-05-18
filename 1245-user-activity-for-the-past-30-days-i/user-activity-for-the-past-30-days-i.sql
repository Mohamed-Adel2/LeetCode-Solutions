SELECT activity_date as day, COUNT(distinct user_id) as active_users
FROM
    Activity 
WHERE activity_date <= '2019-07-27' AND activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY)
GROUP BY activity_date;