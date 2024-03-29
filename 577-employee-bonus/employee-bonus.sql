SELECT name, bonus
FROM Employee e LEFT JOIN Bonus b ON e.empId = b.empId 
WHERE b.bonus < 1000 || b.bonus IS NULL;
