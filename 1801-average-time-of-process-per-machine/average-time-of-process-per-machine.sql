SELECT a1.machine_id, ROUND(AVG(a1.timestamp - a2.timestamp), 3) AS processing_time
FROM Activity a1, Activity a2
WHERE a1.machine_id = a2.machine_id AND a1.process_id = a2.process_id AND a1.activity_type = "end" AND a2.activity_type = "start"
GROUP BY a1.machine_id;