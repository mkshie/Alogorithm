-- 코드를 작성해주세요
select ROUTE, concat(round(sum(D_BETWEEN_DIST),1),'km') total_distance 
,concat(round(avg(D_BETWEEN_DIST),2),'km') average_distance
from subway_distance
group by route
order by round(sum(D_BETWEEN_DIST),1) desc