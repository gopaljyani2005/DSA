

# Write your MySQL query statement below
select (select u.name from (select *, count(*) as total_movie from MovieRating as m group by m.user_id) as m
    left join 
    Users as u on u.user_id = m.user_id order by total_movie desc, u.name limit 1) as results

union all

select (select Movies.title from (select * , avg(m.rating) as rated from (select * from MovieRating as m where m.created_at<='2020-02-29' and m.created_at >='2020-02-01') as m group by m.movie_id) as m left join 
Movies on Movies.movie_id  = m.movie_id order by m.rated desc, Movies.title limit 1) as results;

