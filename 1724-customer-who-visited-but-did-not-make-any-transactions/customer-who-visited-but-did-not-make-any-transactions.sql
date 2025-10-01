# Write your MySQL query statement below
select v.customer_id, count(*) as count_no_trans  from Visits as v where v.visit_id not in (select t.visit_id from Transactions as t) group by v.customer_id;