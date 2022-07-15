-- https://leetcode.com/problems/swap-salary
UPDATE SALARY SET sex = CASE
        WHEN sex = "m" THEN "f"
        ELSE "m"
END;