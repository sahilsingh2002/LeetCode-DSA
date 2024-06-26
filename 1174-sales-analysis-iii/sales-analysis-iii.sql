# Write your MySQL query statement below
select s.product_id,p.product_name from Sales s
join Product p
on s.product_id = p.product_id
where s.sale_date between '2019-01-01' and '2019-03-31'
and (s.product_id) not in (
    select product_id from sales
    where sale_date > '2019-03-31' or sale_date < '2019-01-01'
)
group by s.product_id