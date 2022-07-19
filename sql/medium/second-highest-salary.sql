-- https://leetcode.com/problems/second-highest-salary
SELECT 
(SELECT salary FROM (SELECT salary,
DENSE_RANK () OVER (ORDER BY salary DESC) AS number
FROM Employee) AS salaries
WHERE salaries.number = 2
LIMIT 1) AS SecondHighestSalary