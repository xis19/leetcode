SELECT Id
FROM (
    SELECT (Weather.Temperature - Weather1.Temperature) AS diff, Weather.Id AS Id
    FROM Weather
    LEFT JOIN Weather AS Weather1 ON Weather.Date = DATE_ADD(Weather1.Date, INTERVAL 1 DAY)
) AS tmp
WHERE diff > 0;
