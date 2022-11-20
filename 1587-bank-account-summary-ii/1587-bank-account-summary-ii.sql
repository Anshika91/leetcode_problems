# Write your MySQL query statement below
SELECT u.name,
       SUM(amount) balance
FROM users u
INNER JOIN transactions t ON u.account = t.account
GROUP BY u.name
HAVING balance > 10000
ORDER BY NULL;