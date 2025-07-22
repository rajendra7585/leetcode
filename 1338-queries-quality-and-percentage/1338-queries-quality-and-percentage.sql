# Write your MySQL query statement below
select q.query_name, round(avg(rating/position),2) quality,round(avg(rating<3)*100,2) poor_query_percentage from queries q
group by q.query_name
;