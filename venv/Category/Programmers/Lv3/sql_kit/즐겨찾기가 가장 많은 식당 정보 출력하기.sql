SELECT food_type, rest_id, rest_name, favorites
from rest_info
where (food_type, favorites) in (
    select food_type, max(favorites) over(partition by food_type)
    from rest_info
)
order by food_type desc;