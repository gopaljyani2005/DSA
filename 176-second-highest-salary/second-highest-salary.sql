# Write your MySQL query statement below
select   max(ranktable.salary) as SecondHighestSalary 
    from (select * , dense_rank() over (order by Employee.salary desc) as rankno from Employee) as ranktable where ranktable.rankno = 2;