SELECT
    ABS(point.x - point1.x) AS shortest
FROM
    point
JOIN
    point AS point1 ON point.x != point1.x
ORDER BY shortest
LIMIT 1;
