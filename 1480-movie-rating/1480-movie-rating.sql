(SELECT u.name results
FROM users u
INNER JOIN movieRating m ON u.user_id = m.user_id
GROUP BY u.user_id
ORDER BY COUNT(m.rating) DESC, u.name
LIMIT 1)
union all

(select mo.title results from movies mo inner join 
movierating m on mo.movie_id=m.movie_id
where MONTH(m.created_at)=2 and YEAR(m.created_at)=2020
group by mo.movie_id
order by avg(m.rating) desc,mo.title
limit 1)
;

