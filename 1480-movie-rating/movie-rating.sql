# Write your MySQL query statement below
select distinct(u.name) as results from MovieRating mv
join Users u on u.user_id = mv.user_id
where u.user_id = (
    select movieRating.user_id from movieRating
    join Users us on movieRating.user_id = us.user_id
    group by user_id
    order by count(MovieRating.user_id) desc, us.name asc
    limit 1
)
union all
select distinct (m.title) as results
from MovieRating mv
join Movies m on m.movie_id = mv.movie_id
 where m.movie_id = (
    select MovieRating.movie_id from MovieRating
    join Movies ms
    on MovieRating.movie_id = ms.movie_id
    where MovieRating.created_at like '2020-02-%'
    group by MovieRating.movie_id
    order by avg(rating) desc, ms.title asc
    limit 1
)
