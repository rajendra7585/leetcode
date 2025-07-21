# Write your MySQL query statement below
select p.product_id,if(round(sum(p.price*u.units)/sum(u.units),2),round(sum(p.price*u.units)/sum(u.units),2),0) average_price from Prices p left join unitssold u on
p.product_id=u.product_id and
p.start_date<=u.purchase_date and
p.end_date>=u.purchase_date
group by p.product_id
; 