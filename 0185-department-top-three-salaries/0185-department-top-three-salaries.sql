# Write your MySQL query statement below
select d.name department ,e1.name employee ,e1.salary Salary
from employee e1 join department d on e1.departmentId=d.id
where (select count(distinct(e2.salary)) from
employee e2 where e2.salary>e1.salary
and e1.departmentId=e2.departmentId)<3
