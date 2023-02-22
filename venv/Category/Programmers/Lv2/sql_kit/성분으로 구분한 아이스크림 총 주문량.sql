-- 코드를 입력하세요
with tmp as (
    select flavor, sum(total_order) total_order
    from first_half
    group by flavor
)
SELECT ingredient_type, sum(total_order)
from icecream_info i right join tmp on i.flavor=tmp.flavor
group by ingredient_type
order by total_order;