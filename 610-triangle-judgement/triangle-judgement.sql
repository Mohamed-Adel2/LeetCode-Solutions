SELECT 
    x,
    y,
    z,
    'Yes' AS Triangle
FROM Triangle
WHERE x + y > z && x + z > y && y + z > x
UNION
SELECT
    x,
    y,
    z,
    'No' AS Triangle
FROM Triangle
WHERE x + y <= z || x + z <= y || y + z <= x