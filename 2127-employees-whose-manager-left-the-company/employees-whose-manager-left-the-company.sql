SELECT employee_id 
FROM Employees
WHERE salary < 30000 and manager_id Not IN (SELECT employee_id FROM Employees)
ORDER BY employee_id