# Write your MySQL query statement below
select u.user_id as buyer_id, u.join_date, sum(case when b.buyer_id is not null then 1 else 0 end) as orders_in_2019 from users u
left join orders b
on u.user_id = b.buyer_id and b.order_date like "2019%"
group by u.user_id,u.join_date