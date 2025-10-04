select 
    distinct first_value(q.person_name) over(order by q.weightsum desc) as person_name
    from (SELECT *,
        SUM(queue.weight) OVER (
            ORDER BY queue.turn
            ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
        ) AS weightsum
    FROM Queue AS queue) as q where q.weightsum <= 1000;
