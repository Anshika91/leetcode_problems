# Write your MySQL query statement below

SELECT stock_name, 
       Sum(CASE 
             WHEN operation = 'Buy' THEN -price 
             ELSE price 
           END) AS capital_gain_loss 
FROM   stocks 
GROUP  BY stock_name 
ORDER  BY NULL; 