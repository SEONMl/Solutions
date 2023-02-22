-- 코드를 입력하세요
SELECT animal_id, name
from (
    select row_number() over(order by datediff(o.datetime, i.datetime) desc) r,
    i.animal_id, i.name
    from animal_ins i right join animal_outs o
        on i.animal_id=o.animal_id
      ) tmp
where tmp.r<=2;


-- 코드를 입력하세요
SELECT o.animal_id, o.name
from animal_ins i right join animal_outs o 
    on i.animal_id = o.animal_id
order by datediff(o.datetime, i.datetime) desc
limit 2;