select e.name,b.bonus from employee e
left join bonus b
on e.empId = b.empId
where bonus is NULL or bonus<1000