SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month,country,count(id) trans_count,sum(if(state="approved",1,0))  approved_count, sum(amount) trans_total_amount ,sum(if(state="approved",amount,0)) approved_total_amount
FROM Transactions
group by month ,country;
