-- 코드를 입력하세요
SELECT member_id, member_name, gender, date_of_birth
FROM Member_profile
where tlno is not null 
    and gender='W'
    and month(date_of_birth)=3;