-- https://leetcode.com/problems/delete-duplicate-emails
WITH MinId AS (
SELECT MIN(id)
FROM PERSON
GROUP BY email)
DELETE FROM Person WHERE id NOT IN 
    (SELECT * FROM MinId);