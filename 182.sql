SELECT Email
FROM (
    SELECT COUNT(*) AS cc, Email
    FROM Person
    GROUP BY Email
) AS tmp
WHERE tmp.cc > 1;
