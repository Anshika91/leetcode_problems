# Write your MySQL query statement below
select 
   name, population,area 
FROM
    world 
WHERE
    area >= 3000000 
UNION  
select 
   name, population,area 
FROM 
    world 
WHERE 
    population >= 25000000
;