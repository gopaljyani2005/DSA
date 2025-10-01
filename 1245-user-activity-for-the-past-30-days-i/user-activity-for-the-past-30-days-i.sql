# Write your MySQL query statement below

select a.activity_date as day , count(*) as active_users from (select * from Activity as a 
    where a.activity_date 
    between DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27' 
    group by a.user_id, a.activity_date ) as a group by  a.activity_date;
    