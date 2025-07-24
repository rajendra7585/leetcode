# Write your MySQL query statement below
select round(sum(tiv_2016),2) tiv_2016 from insurance
where tiv_2015 in (select tiv_2015 from insurance group by tiv_2015
having count(*)>1)
AND (lat,lon) in (
    select lat,lon from insurance 
    group by lat,lon
    having count(*)=1
)