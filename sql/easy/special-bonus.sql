-- https://leetcode.com/problems/calculate-special-bonus
SELECT employee_id, 
CASE 
    WHEN MOD(employee_id, 2) = 1 && LEFT(name, 1) <> "M"  THEN salary
    ELSE 0
END bonus
FROM Employees
ORDER BY employee_id;