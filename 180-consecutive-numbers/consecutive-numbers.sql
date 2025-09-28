# Write your MySQL query statement below
select distinct result.num as ConsecutiveNums from 
(select Logs.num, LAG(Logs.num,1) over (order by Logs.id)  as prev1, 
                LAG(Logs.num,2) over (order by Logs.id) as prev2 from Logs) as result 
                where result.num=result.prev1 and result.num = result.prev2;