select c2.Name as Customers
from Customers c2
where c2.Id 
not in 
(select o.CustomerId
from Customers c, Orders o
where c.Id = o.CustomerId)
