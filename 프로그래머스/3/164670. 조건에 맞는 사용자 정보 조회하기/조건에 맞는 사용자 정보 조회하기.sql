-- 코드를 입력하세요
-- 중고거래 게시물을 3건 이상한 사람 관련해서 출력하기

-- select * from USED_GOODS_USER
-- select * from USED_GOODS_BOARD




-- select u.user_id from USED_GOODS_USER as u left join USED_GOODS_BOARD as b on u.user_id = b.writer_id group by user_id having count(*) > 3



select r.user_id as USER_ID , r.nickname as NICKNAME , concat(city , " " , street_address1 , " " , street_address2) as 전체주소
, concat(
    substring(tlno , 1 , 3), '-',
    substring(tlno , 4 , 4), '-',
    substring(tlno , 8)
) as 전화번호
from USED_GOODS_USER as r where r.user_id in (select u.user_id from USED_GOODS_USER as u left join USED_GOODS_BOARD as b on u.user_id = b.writer_id group by user_id having count(*) > 2 ) 
order by  r.user_id desc