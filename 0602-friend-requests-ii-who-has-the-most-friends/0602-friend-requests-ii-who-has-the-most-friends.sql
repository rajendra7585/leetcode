# Write your MySQL query statement below
select ans.requester_id id ,count(ans.accepter_id) num from(select requester_id,accepter_id from RequestAccepted
union
select accepter_id,requester_id from RequestAccepted)ans
group by requester_id
order by count(ans.accepter_id) desc
limit 1