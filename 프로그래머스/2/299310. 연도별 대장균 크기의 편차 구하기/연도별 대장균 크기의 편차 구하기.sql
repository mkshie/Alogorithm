-- 코드를 작성해주세요
select year(a.differentiation_date) YEAR , (b_ecoli.m-a.size_of_colony) as YEAR_DEV , a.id
from ecoli_data a join 
(
    select max(b.SIZE_OF_COLONY) as m , year(b.DIFFERENTIATION_DATE) as y
    from ecoli_data b
    group by year(b.DIFFERENTIATION_DATE)
) b_ecoli
on year(a.differentiation_date) = b_ecoli.y
order by YEAR,YEAR_DEV