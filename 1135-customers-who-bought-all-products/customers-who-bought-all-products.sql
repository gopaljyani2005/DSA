# Write your MySQL query statement below


select c.customer_id from (select * , count(*) as product_counts 
        from (select distinct * from Customer) as c 
        group by c.customer_id) as c inner join 
        (select *, count(*) over() as product_count from Product) as Product on Product.product_key = c.product_key where c.product_counts  = Product.product_count;
