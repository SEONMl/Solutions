-- 코드를 입력하세요
SELECT product_code,
    (price * (SELECT SUM(sales_amount)
            FROM OFFLINE_SALE O
             WHERE P.product_id=O.product_id
            GROUP BY product_id)) AS sales
FROM PRODUCT P
ORDER BY sales DESC, product_code;

-- 9분