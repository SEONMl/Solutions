-- 코드를 입력하세요
with tmp as (
    SELECT date_format(sales_date,"%Y-%m-%d") as sales_date, product_id, user_id, sales_amount
    from online_sale 
    where sales_date >='2022-03-01' and sales_date<='2022-03-31'
    union all
    select date_format(sales_date,"%Y-%m-%d") as sales_date, product_id,null as user_id, sales_amount
    from offline_sale 
    where sales_date >='2022-03-01' and sales_date<='2022-03-31'
)
select sales_date, product_id,user_id,sales_amount
from tmp
order by sales_date, product_id, user_id;
-- null에 따옴표 없어야 정답 -_-...