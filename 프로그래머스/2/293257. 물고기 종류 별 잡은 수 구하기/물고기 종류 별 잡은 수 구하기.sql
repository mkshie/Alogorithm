select count(*) as FISH_COUNT , ni.fish_name as FISH_NAME
from fish_info i left join fish_name_info ni on i.fish_type = ni.fish_type
group by ni.fish_name
order by count(*) desc