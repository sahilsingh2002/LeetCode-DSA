# Write your MySQL query statement below
select distinct actor_id, director_id from actordirector
where (actor_id, director_id) in(
    select actor_id, director_id from actordirector
    group by actor_id,director_id
    having count(concat(actor_id,director_id))>=3
)