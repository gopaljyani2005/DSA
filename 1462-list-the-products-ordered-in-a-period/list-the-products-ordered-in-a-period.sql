# Write your MySQL query statement below
select p.product_name, o.totalcount as unit from Products as p 
    left join 
    (select *,sum(o.unit) as totalcount from Orders as o where o.order_date<='2020-02-29' and o.order_date>='2020-02-01'
    group  by o.product_id) as o on o.product_id = p.product_id
    where o.totalcount>=100;