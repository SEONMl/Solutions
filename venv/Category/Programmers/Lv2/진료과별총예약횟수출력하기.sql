-- 코드를 입력하세요
SELECT mcdp_cd AS '진료과 코드', COUNT(*) AS '5월예약건수'
FROM Appointment
WHERE apnt_ymd>='2022-05-01' AND apnt_ymd<='2022-05-31'
GROUP BY mcdp_cd
ORDER BY 5월예약건수, mcdp_cd;
-- 7'50''