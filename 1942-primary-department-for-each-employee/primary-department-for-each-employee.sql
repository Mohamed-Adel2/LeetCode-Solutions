SELECT DISTINCT e1.employee_id, e1.department_id 
FROM Employee e1
WHERE primary_flag = 'Y' OR 1 = (SELECT COUNT(*) FROM Employee e2 WHERE e1.employee_id = e2.employee_id);