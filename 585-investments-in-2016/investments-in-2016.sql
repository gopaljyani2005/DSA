# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016 from 
    (select l.pid, l.tiv_2016,l.2015total,r.latlontotal from 
        (select i1.pid,i1.tiv_2016, i2.2015total from Insurance as i1 
        left join 
        (select i.tiv_2015,  count(*) 2015total from Insurance as i group by i.tiv_2015) as i2 
        on i1.tiv_2015 = i2.tiv_2015) as l
    left join
        (select i3.pid, i4.latlontotal from Insurance as i3 
        left join
        (select i.lat, i.lon , count(*) as latlontotal from Insurance  as i group by i.lat , i.lon) as i4
        on i4.lat = i3.lat and i4.lon =i3.lon) as r
            
    on r.pid = l.pid) as final where final.2015total>1 and final.latlontotal<2;