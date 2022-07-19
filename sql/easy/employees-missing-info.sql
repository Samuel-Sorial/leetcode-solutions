-- https://leetcode.com/problems/employees-with-missing-information/
SELECT T.employee_id
FROM (
(SELECT e.employee_id, s.salary, e.name
FROM Employees AS e LEFT JOIN Salaries AS s
ON e.employee_id = s.employee_id)
UNION
(SELECT s.employee_id, salary, e.name
FROM Employees AS e RIGHT JOIN Salaries AS s
ON e.employee_id = s.employee_id) AS T
WHERE T.salary IS NULL OR T.name IS NULL)
ORDER BY T.employee_id ASC;