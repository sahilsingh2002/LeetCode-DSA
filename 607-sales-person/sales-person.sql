# Write your MySQL query statement below
select distinct s.name from Salesperson s
where sales_id not in(
    select sales_id from orders o
    where com_id not in (
        select com_id from company
        where name not like "RED"
    )
)