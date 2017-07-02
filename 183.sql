SELECT Name AS Customers
FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.Id IS NULL;

# Note: When comparing NULL, "IS" keyword is required in MySQL.
