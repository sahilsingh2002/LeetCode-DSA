select e.name from employee e
left join employee e2
on e.id = e2.managerId
group by e.id
having count(e.id)>=5

