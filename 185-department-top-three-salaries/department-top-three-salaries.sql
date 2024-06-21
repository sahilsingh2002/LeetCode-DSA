select Department,Employee,Salary from (
    select d.name as Department,e.name as Employee, e.salary as Salary, dense_rank() over (partition by e.departmentId order by e.salary desc) as ranks from employee e
    left join department d
    on e.departmentId = d.id
) as rnk
where ranks<=3
