SELECT DISTINCT num AS ConsecutiveNums 
FROM Logs
Where (id + 1, num) IN(
    SELECT id, num
    FROM Logs
)
AND (id + 2, num) IN(
    SELECT id, num
    FROM Logs
)