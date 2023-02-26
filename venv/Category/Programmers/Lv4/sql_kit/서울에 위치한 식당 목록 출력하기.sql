-- 코드를 입력하세요
with tmp as (
    select round(avg(review_score),2) as score, rest_id
    from rest_review
    group by rest_id
)
SELECT i.rest_id, rest_name, food_type, favorites, address, score
from rest_info i right join tmp 
    on i.rest_id=tmp.rest_id
where address like "서울%"
order by score desc, favorites desc;
-- 서울특별시% ㄴㄴ
-- 서울%       ㅇㅇ 
-- ㅋㅋ