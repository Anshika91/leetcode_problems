# Write your MySQL query statement below
select r.name, 
case when x.td is null
then 0
else x.td
end travelled_distance
from Users r
left join
(
    select user_id, sum(distance) td
    from Rides 
    group by user_id
) x
on r.id = x.user_id
order by travelled_distance desc,  r.name;