SELECT 
    x,
    y,
    z,
    IF((x + y) > z && (y + z) > x && (x + z) > y, 'Yes', 'No') AS triangle
FROM Triangle;