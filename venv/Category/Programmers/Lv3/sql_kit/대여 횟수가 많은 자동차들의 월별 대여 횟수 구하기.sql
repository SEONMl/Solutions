-- 코드를 입력하세요
with tmp as (
    select month(start_date) month,car_id, count(*) records
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date<='2022-10-31' and start_date>='2022-08-01'
    group by car_id, month(start_date)
)
select month, car_id, records
from tmp
where car_id in (select car_id from tmp group by car_id having sum(records)>=5)
order by month, car_id desc;