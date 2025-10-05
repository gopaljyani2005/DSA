# Write your MySQL query statement below

select * from (select r.Department, r.Employee, r.salary as Salary from 
Employee as l 
left join 
(select * from (select * ,
    dense_rank() over(partition by final.department order by final.salary desc) as ranking
    from 
    (select e.id,e.name as Employee, e.salary,d.name as Department from Employee as e 
    left join 
    Department as d on e.departmentId = d.id) 
    as final) as f where f.ranking<=3) as r
on l.id = r.id) as f where f.department is not null;