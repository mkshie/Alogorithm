-- 코드를 입력하세요
SELECT car_type , count(options) as CARS
from car_rental_company_car
WHERE options LIKE '%통풍시트%'
   OR options LIKE '%열선시트%'
   OR options LIKE '%가죽시트%'
group by car_type
order by car_type