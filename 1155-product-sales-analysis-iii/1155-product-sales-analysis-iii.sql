# Write your MySQL query statement below
select product_id,year as first_year ,quantity,price from sales where(product_id,year) in(
select product_id ,min(year) ear from sales
group by product_id);