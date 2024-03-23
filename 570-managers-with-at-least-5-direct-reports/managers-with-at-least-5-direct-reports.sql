select e1.name
from Employee e1
where e1.id in(
    select e2.managerId
    from Employee e2
    group by e2.managerId
    having count(e2.managerId) >= 5
);