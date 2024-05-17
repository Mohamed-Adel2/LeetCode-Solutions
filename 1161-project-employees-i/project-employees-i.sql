SELECT project_id , COALESCE(ROUND (SUM(experience_years)/COUNT(e.employee_id), 2),0) AS average_years

FROM Project p LEFT OUTER JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY project_id;