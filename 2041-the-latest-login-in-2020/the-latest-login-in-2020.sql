select user_id,max(if(time_stamp like "2020%",time_stamp,0)) as last_stamp from Logins
group by user_id
having last_stamp like "2020%"
