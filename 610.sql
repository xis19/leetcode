SELECT
    x, y, z, IF(x > 0 AND y > 0 AND z > 0 AND x + y > z AND y + z > x AND z + x > y, 'Yes', 'No') AS triangle
FROM
    triangle;
