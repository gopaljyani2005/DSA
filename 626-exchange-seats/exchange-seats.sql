# Write your MySQL query statement below
select (case 
                when s.id%2=0
                    then s.id-1
                    else (case
                            when s.id = s.last
                                    then s.id
                                    else s.id+1
                            end)
                end) as id, s.student from (select *, count(*) over() as last from Seat) as s order by id;