# Write your MySQL query statement below
select r.contest_id,round(count(r.user_id)*100/(select count(user_id ) from users),2) percentage from Users u right join Register r on
u.user_id=r.user_id
group by r.contest_id
order by count(r.user_id) desc,contest_id

;