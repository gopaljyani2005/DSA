# Write your MySQL query statement below
select round(100*(sum(case when d.order_date=d.customer_pref_delivery_date then 1 else 0 end)/sum(case when true then 1 else 0 end)),2) 
as immediate_percentage 
 from (select *, first_value(order_date) 
    over(partition by customer_id order by order_date) as first_order
    from Delivery
    as d) as d where d.first_order = d.order_date;
