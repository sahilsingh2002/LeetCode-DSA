# Write your MySQL query statement below
select name as customers from Customers
left join orders
on customers.id = orders.customerId
where orders.customerId is null