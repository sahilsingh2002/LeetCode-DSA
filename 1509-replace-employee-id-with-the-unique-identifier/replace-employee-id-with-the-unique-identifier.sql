# Write your MySQL query statement below
select (u.unique_id),name from employees e
left join employeeUNI u
on e.id = u.id;