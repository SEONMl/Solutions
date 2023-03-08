select member_name, review_text, date_format(review_date,"%Y-%m-%d") 
from member_profile m join rest_review r
    on m.member_id=r.member_id
where m.member_id in 
    (select member_id
    from rest_review
    group by member_id
    having count(*)=(
        select max(c)
        from (select count(*) over(partition by member_id) c
            from rest_review) tmp))
order by review_date, review_text;