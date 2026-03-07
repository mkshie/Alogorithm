-- 코드를 입력하세요
select CATEGORY , PRICE as MAX_PRIXE , PRODUCT_NAME
from
    (SELECT CATEGORY , PRICE , PRODUCT_NAME , RANK() OVER(PARTITION BY CATEGORY order by price desc) as rn
    from FOOD_PRODUCT
    where CATEGORY in ('과자' , '국' , '김치' , '식용유')) t
where rn = 1
order by PRICE desc