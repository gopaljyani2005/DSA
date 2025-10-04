# Write your MySQL query statement below

select final.requester_id as id ,sum(final.sum1) as num from (
    select r.requester_id , count(*) as sum1 from RequestAccepted as r group by r.requester_id
    union all
    select r.accepter_id as requester_id , count(*) as sum1 from RequestAccepted as r group by r.accepter_id) as final
    group by final.requester_id order by num desc limit 1;