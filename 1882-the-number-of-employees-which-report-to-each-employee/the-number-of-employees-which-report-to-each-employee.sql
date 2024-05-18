SELECT e1.employee_id, e1.name, COUNT(e2.employee_id) as reports_count, ROUND(AVG(e2.age)) AS average_age
FROM Employees e1, Employees e2
WHERE e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY employee_id;