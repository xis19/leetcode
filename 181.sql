SELECT Employee.Name AS Employee
FROM Employee
JOIN Employee AS Employee1 ON Employee.ManagerId = Employee1.Id
WHERE Employee.Salary > Employee1.Salary;
