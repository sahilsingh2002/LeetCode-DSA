# Write your MySQL query statement below
select t.request_at as "Day", 
round(avg(case when status like 'cancelled%' then 1 else 0 end),2) as "Cancellation Rate"
from trips t
join users u on t.client_id = u.users_id
join users u1 on t.driver_id = u1.users_id
where u.banned!="Yes" and u1.banned!="Yes" and t.request_at between "2013-10-01" and "2013-10-03"
group by t.request_at 
order by t.request_at