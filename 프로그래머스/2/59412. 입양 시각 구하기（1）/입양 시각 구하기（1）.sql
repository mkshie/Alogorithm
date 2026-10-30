-- 코드를 입력하세요
SELECT hour(datetime) HOUR , count(*) from animal_outs
where hour(datetime) >=9 and hour(datetime) < 20
group by hour(datetime)
order by hour(datetime)