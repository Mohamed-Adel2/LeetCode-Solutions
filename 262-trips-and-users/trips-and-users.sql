SELECT
    request_at AS Day,
    ROUND(SUM(IF(status != 'completed', 1, 0)) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
WHERE client_id NOT IN (SELECT users_id FROM Users WHERE banned = 'Yes')
AND driver_id NOT IN (SELECT users_id FROM Users WHERE banned = 'Yes')
AND request_at BETWEEN "2013-10-01" and "2013-10-03"
GROUP BY request_at