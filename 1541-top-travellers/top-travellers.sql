# Write your MySQL query statement below
select u.name,coalesce(sum(r.distance),0) as travelled_distance from users u
left join rides r on u.id = r.user_id
group by u.id
order by sum(r.distance) desc, u.name