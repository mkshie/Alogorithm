-- 코드를 작성해주세요
select distinct id , email , first_name , last_name
from developers 
where id in(select d.id
    from developers d join skillcodes s
    on d.skill_code & s.code > 0 and (s.name ='Python' or s.name = 'C#')
    )
order by id