select round(count(distinct player_id)/(select count(distinct player_id) from activity),2) as fraction from activity
where (player_id,date_sub(event_date,INTERVAL 1 DAY)) in (
   select player_id,min(event_date) from activity a1
    group by a1.player_id
) 