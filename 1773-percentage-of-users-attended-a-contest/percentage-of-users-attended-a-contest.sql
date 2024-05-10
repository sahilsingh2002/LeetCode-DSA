select r.contest_id,round(count(r.contest_id)*100/(select count(u.user_id) from users u),2) as percentage from register r
group by r.contest_id
order by percentage desc, r.contest_id
