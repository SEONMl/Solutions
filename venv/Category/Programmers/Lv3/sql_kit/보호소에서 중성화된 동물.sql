-- 코드를 입력하세요
with tmp as (
    select SEX_UPON_INTAKE,animal_id
    from animal_ins i
    where SEX_UPON_INTAKE like '%Intact%'
)
SELECT o.animal_id, o.animal_type, o.name
from animal_outs o right join tmp
    on o.animal_id=tmp.animal_id
where SEX_UPON_OUTCOME like '%Spayed%' or SEX_UPON_OUTCOME like '%Neutered%'
order by o.animal_id;