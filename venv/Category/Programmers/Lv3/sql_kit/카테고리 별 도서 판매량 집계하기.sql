-- 코드를 입력하세요
with tmp as(
    select sum(sales) total_sales, book_id
    from book_sales
    where month(sales_date)=1
    group by book_id
)
SELECT category, sum(total_sales)
from book b left join tmp
    on b.book_id=tmp.book_id
group by category
order by category;