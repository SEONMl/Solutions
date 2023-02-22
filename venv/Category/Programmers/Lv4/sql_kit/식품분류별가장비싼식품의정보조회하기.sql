-- 코드를 입력하세요
SELECT category, price, product_name
from food_product 
where (category, price) in (select category, max(price) price
      from food_product
    where category in ('과자','국','김치','식용유') 
      group by category
      ) 
order by price desc;