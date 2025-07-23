# Write your MySQL query statement below
select ans.person_name from 
(select person_id,person_name,turn,sum(weight) over(order by turn) total_weight from queue) ans
where total_weight<=1000
order by turn desc
limit 1;