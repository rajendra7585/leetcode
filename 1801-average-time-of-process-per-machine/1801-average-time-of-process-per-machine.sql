# Write your MySQL query statement below
select k.machine_id,round(sum(k.diff)/count(k.process_id),3)processing_time from(
select a1.machine_id,a1.process_id,(a2.timestamp-a1.timestamp)diff from activity a1 join activity a2 on
(a1.machine_id=a2.machine_id and
a1.process_id=a2.process_id and
a1.activity_type="start" and
a2.activity_type="end")) k group by 
k.machine_id;