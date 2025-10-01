# Write your MySQL query statement below

select round(sum(case when d2.customer_pref_delivery_date = d2.order_date then 100 else 0 end)/sum(case when true then 1 else 0 end),2) as immediate_percentage 
from (select d.customer_id, min(d.order_date) as order_date from Delivery as d group by d.customer_id) 
as d1
left join (select * from Delivery) 
as d2 
on d1.customer_id = d2.customer_id and d1.order_date = d2.order_date;