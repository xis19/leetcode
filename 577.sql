SELECT
    Employee.name AS name,
    Bonus.bonus AS bonus
FROM
    Employee
LEFT OUTER JOIN Bonus ON Employee.empId = Bonus.empId
WHERE
    Bonus.bonus < 1000 OR Bonus.bonus IS NULL;
