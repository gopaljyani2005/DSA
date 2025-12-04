# Write your MySQL query statement below
select Products.product_id
from Products 
where Products.low_fats ='Y'
and Products.recyclable = 'Y';