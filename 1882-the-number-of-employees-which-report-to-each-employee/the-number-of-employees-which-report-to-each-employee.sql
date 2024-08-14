SELECT
    m.employee_id,
    m.name,
    COUNT(*) AS reports_count,
    ROUND(AVG(e.age), 0) AS average_age
FROM Employees e, Employees m
WHERE e.reports_to = m.employee_id
GROUP BY m.employee_id
ORDER BY m.employee_id;
