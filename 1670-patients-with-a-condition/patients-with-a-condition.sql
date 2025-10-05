# Write your MySQL query statement below
select * from Patients as p where left(p.conditions ,5) = 'DIAB1' or instr(p.conditions,'DIAB1') and instr(p.conditions,' DIAB1');