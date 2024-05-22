SELECT e.employee_id , e.name , COUNT(m.reports_to) as reports_count,
       ROUND(AVG(m.age)) as average_age
FROM Employees e inner join Employees m
ON e.employee_id = m.reports_to
GROUP BY m.reports_to
ORDER BY e.employee_id
