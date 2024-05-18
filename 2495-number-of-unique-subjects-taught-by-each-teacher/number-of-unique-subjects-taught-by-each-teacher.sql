SELECT teacher_id, COUNT(distinct subject_id) as cnt
FROM
    Teacher
GROUP BY teacher_id;