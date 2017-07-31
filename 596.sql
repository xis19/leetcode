SELECT
    class
FROM (
    SELECT
        COUNT(*) AS num, CLASS
    FROM (
        SELECT
            DISTINCT CONCAT(student, class), student, class
        FROM
            courses
    ) AS TMP1
    GROUP BY
        class
) AS TMP2
WHERE
    num >= 5;
