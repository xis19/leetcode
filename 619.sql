-- The external SELECT ensures NULL is used when the inner select returns empty
SELECT (
    SELECT
    num
    FROM (
        SELECT
        num, COUNT(*) AS count
        FROM
        number
        GROUP BY
        num
        HAVING
        count = 1
        ORDER BY
        num
        DESC
        LIMIT 1
    ) AS temp
) AS num;
