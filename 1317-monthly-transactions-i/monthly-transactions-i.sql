# Write your MySQL query statement below
select concat(final.year, '-', LPAD(final.month,2,'0')) as month, 
        final.country, count(*) as trans_count,
        count(case when final.state='approved' then 1 end) as approved_count, 
        sum(final.amount) as trans_total_amount,
        sum(case when final.state='approved' then final.amount else 0 end) as approved_total_amount 
        from 
        (select *,YEAR(t.trans_date) as year, MONTH(t.trans_date) as month  from Transactions as t) as final group by final.year, final.month, final.country;