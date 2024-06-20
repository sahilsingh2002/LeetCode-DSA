# Write your MySQL query statement belo
select d.name as department, e.name as employee,e.salary as salary from employee e
join department d 
on e.departmentId = d.id
where (e.departmentId,e.salary) in (
    select departmentId,max(salary) from employee
    group by departmentId
)