# Write your MySQL query statement below
select S.student_id,S.student_name,SU.subject_name,COUNT(p.student_id) attended_exams from students s cross join subjects su 
left join examinations p on
s.student_id=p.student_id and su.subject_name=p.subject_name
group by s.student_id,su.subject_name 
order by s.student_id,su.subject_name 
;