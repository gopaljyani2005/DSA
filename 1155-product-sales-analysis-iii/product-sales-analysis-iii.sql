# Write your MySQL query statement below


select f.product_id, f.year as first_year, f.quantity, f.price from (select *, dense_rank() over(partition by s.product_id order by s.year) as firstproduct from Sales as s) as f where f.firstproduct  =1;