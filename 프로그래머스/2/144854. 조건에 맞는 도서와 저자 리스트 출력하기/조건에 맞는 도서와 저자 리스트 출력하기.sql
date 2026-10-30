-- 코드를 입력하세요
SELECT book_id , author_name , date_format(published_date,'%Y-%m-%d') as published_date
from book b join author a
on b.author_id = a.author_id
where b.category ='경제'
order by b.published_date asc