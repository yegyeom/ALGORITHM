**[1. 우유와 요거트가 담긴 장바구니 (Level 4)](https://programmers.co.kr/learn/courses/30/lessons/62284)**

```sql
SELECT DISTINCT A.CART_ID
FROM CART_PRODUCTS A INNER JOIN CART_PRODUCTS B ON A.CART_ID = B.CART_ID
WHERE (A.NAME IN ('Milk', 'Yogurt') and B.NAME IN ('Milk', 'Yogurt')) and A.NAME != B.NAME
ORDER BY A.CART_ID
```

<br/>

**[2. 헤비 유저가 소유한 장소 (Level 3)](https://programmers.co.kr/learn/courses/30/lessons/77487)**

```sql
SELECT *
FROM PLACES
WHERE HOST_ID IN (
    SELECT HOST_ID
    FROM PLACES
    GROUP BY HOST_ID
    HAVING COUNT(*) >= 2
)
ORDER BY ID
```
