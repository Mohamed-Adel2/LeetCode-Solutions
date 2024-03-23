SELECT s1.user_id, ROUND(
    (SELECT count(c1.user_id) FROM Confirmations c1 WHERE action='confirmed' and c1.user_id=s1.user_id) / 
    COALESCE(
        NULLIF((SELECT COUNT(c2.user_id) FROM Confirmations c2 WHERE c2.user_id = s1.user_id), 0), 
            1
        )
    , 2) AS confirmation_rate
from Signups s1;