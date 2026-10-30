-- 코드를 입력하세요
SELECT book_id , Date_format(PUBLISHED_DATE , '%Y-%m-%d') PUBLISHED_DATE from book where year(published_date) = 2021 and category ='인문'
Order by published_date