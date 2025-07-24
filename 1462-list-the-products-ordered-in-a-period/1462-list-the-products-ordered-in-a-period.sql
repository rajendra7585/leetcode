# Write your MySQL query statement below
select p.product_name product_name ,sum(o.unit) unit from products p join
orders o on p.product_id=o.product_id
where month(o.order_date)='2' and YEAR(o.order_date)='2020'
group by p.product_id
having sum(o.unit)>=100
;