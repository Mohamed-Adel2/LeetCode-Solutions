SELECT
    IFNULL(MAX(salary), NULL) AS SecondHighestSalary
FROM Employee
WHERE salary != (SELECT MAX(salary) FROM Employee)