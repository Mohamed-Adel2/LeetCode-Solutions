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
    'No' AS asd
FROM Triangle
WHERE x + y <= z || x + z <= y || y + z <= x