# Write your MySQL query statement below
# Time:  O(n)
# Space: O(1)

SELECT (SELECT MAX(Salary) FROM Employee WHERE Salary NOT IN (SELECT MAX(Salary) FROM Employee)) SecondHighestSalary;
