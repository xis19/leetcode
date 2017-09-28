SELECT
    customer_number
FROM
    (
        SELECT
            COUNT(*) AS count, customer_number
        FROM
            orders
        GROUP BY
            customer_number
        ORDER BY count DESC
        LIMIT 1
    ) AS s;
