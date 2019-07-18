# Write your MySQL query statement below
SELECT a.name AS Employee
FROM Employee a, Employee b
WHERE a.ManagerId=b.Id and a.Salary>b.Salary;