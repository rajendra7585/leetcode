# Write your MySQL query statement below
select round(count(player_id)/(select count(distinct(player_id)) from activity),2) fraction
 from activity a where (player_id, date_sub(event_date,INTERVAL 1 day)) in 
(select player_id, min(event_date) event_date from activity
group by player_id) 
;