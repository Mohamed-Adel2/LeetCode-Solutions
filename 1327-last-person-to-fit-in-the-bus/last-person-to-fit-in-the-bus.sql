Select p.person_name from Queue p
where 1000 >= (Select Sum(pp.weight) from Queue pp where pp.turn <= p.turn)
ORDER BY turn DESC
LIMIT 1;