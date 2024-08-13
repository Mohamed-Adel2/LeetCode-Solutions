SELECT s.student_id, s.student_name, ss.subject_name, COUNT(e.subject_name) AS attended_exams
FROM Students s JOIN Subjects ss
LEFT JOIN Examinations e
ON s.student_id = e.student_id AND ss.subject_name = e.subject_name
GROUP BY s.student_id, ss.subject_name
ORDER BY s.student_id, ss.subject_name;
