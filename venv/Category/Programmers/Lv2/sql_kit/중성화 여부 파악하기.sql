-- 코드를 입력하세요
SELECT animal_id, name, 
    case
        when SEX_UPON_INTAKE like '%Neutered%' 
            or SEX_UPON_INTAKE like '%Spayed%' then "O"
        else "X"
    end
from animal_ins;