SELECT
    c0.seat_id AS seat_id
FROM cinema c0
LEFT JOIN cinema c1 ON c1.seat_id = c0.seat_id - 1
LEFT JOIN cinema c2 ON c2.seat_id = c0.seat_id + 1
WHERE
    c0.free = 1 AND (c1.free = 1 OR c2.free = 1);
