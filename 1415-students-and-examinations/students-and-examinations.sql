SELECT *,
       (SELECT COUNT(*)
        FROM Examinations e
        WHERE e.student_id = s.student_id 
        AND e.subject_name = s.subject_name) AS attended_exams
FROM (SELECT * FROM Students CROSS JOIN Subjects) AS s
ORDER BY s.student_id, s.subject_name;