# Write your MySQL query statement below

select 'Low Salary' as category ,count(*) as accounts_count from Accounts as a where a.income<20000
union
select 'Average Salary' as category ,count(*) as accounts_count from Accounts as a where a.income >= 20000 and a.income<=50000
union
select 'High Salary' as category ,count(*) as accounts_count from Accounts as a where a.income >50000;