SELECT w2.id 
FROM Weather w1 inner join Weather w2
on datediff(w2.recordDate , w1.recordDate)=1 
    and w2.temperature > w1.temperature