-- 코드를 입력하세요


select car_id , 
    case
        when exists(
            select 1 from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
                where start_date <= DATE '2022-10-16' and end_date >= DATE '2022-10-16' and h.car_id = c.car_id
        ) THEN '대여중'
            ELSE '대여 가능'
            END as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY as c
group by car_id
order by car_id desc



# SELECT car_id , "대여중" as AVAILABILITY from CAR_RENTAL_COMPANY_RENTAL_HISTORY as car
# where start_date <= DATE '2022-10-16' and end_date >= DATE '2022-10-16'
# order by car_id desc

# 2022년 10월 16일에  대여 가능한애들은 대여가능 , 아니라면 대여중으로 
# 먼저 대여 가능한 애들부터 
# SELECT car_id , "대여 가능" as AVAILABILITY from CAR_RENTAL_COMPANY_RENTAL_HISTORY as car
# where start_date > DATE '2022-10-16' or end_date < DATE '2022-10-16'
#UNION