# Write your MySQL query statement below


select c.visited_on, 
    sum(c.amount) over(order by c.visited_on rows between 6 preceding and  current row)  as amount,
    round(avg(c.amount) over(order by c.visited_on rows between 6 preceding and  current row),2)  as average_amount
        from 
        (select c.visited_on , sum(c.amount) as amount from Customer as c group by c.visited_on) as c 
        LIMIT 18446744073709551615 OFFSET 6;