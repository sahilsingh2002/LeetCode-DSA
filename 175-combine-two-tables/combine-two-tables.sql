# Write your MySQL query statement below
select firstName,lastName,address.city,address.state from person
left join address
on person.personId = Address.personId