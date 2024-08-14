WITH cte AS(
    SELECT 
        employee_id,
        SUM(IF(primary_flag = 'Y', 1, 0)) AS y,
        SUM(IF(primary_flag = 'N', 1, 0)) AS n
    FROM Employee
    GROUP BY employee_id
)
SELECT
    e.employee_id,
    e.department_id
FROM Employee e, cte c
WHERE e.employee_id = c.employee_id
AND (e.primary_flag = 'Y' OR (c.n = 1 AND c.y = 0));