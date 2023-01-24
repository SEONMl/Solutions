-- 코드를 입력하세요
SELECT P.product_id, product_name, tmp.a*price as total_sales
FROM Food_product P INNER JOIN (
        SELECT O.product_id, SUM(amount) AS a
        FROM Food_order O
        WHERE produce_date>='2022-05-01' and produce_date<='2022-05-31'
        GROUP BY product_id
    )tmp 
    ON P.product_id=tmp.product_id
ORDER BY total_sales DESC, product_id;
-- 13'