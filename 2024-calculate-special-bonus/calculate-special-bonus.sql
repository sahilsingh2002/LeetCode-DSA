select employee_id, if(employee_id%2=0,0,if(name not like "M%",salary,0) ) as bonus from Employees
order by employee_id
