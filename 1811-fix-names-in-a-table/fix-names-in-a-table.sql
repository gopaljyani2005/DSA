# Write your MySQL query statement below
select u.user_id, 
    concat(upper(left(u.name,1)), 
    lower(right(u.name,length(u.name)-1))) as name 
    from Users as u order by u.user_id 