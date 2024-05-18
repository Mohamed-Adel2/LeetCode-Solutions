SELECT distinct class
FROM Courses
GROUP BY class
HAVING COUNT(class) > 4;

