# GROUP BY

**[1. 고양이와 개는 몇 마리 있을까 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59040)**

```sql
SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) as COUNT
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE
```

<br/>

**[2. 동명 동물 수 찾기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59041)**

```sql
SELECT NAME, COUNT(NAME) as COUNT
FROM ANIMAL_INS
GROUP BY NAME
HAVING COUNT(NAME) >= 2
ORDER BY NAME
```

<br/>

**[3. 입양 시각 구하기(1) (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59412)**

```sql
SELECT HOUR(DATETIME) as HOUR, COUNT(HOUR(DATETIME)) as COUNT
FROM ANIMAL_OUTS
GROUP BY HOUR(DATETIME)
HAVING HOUR > 8 and HOUR < 20
ORDER BY HOUR(DATETIME)
```

<br/>

**[4. 입양 시각 구하기(2) (Level 4)](https://programmers.co.kr/learn/courses/30/lessons/59413)**

```sql
SET @HOUR := -1;
SELECT (@HOUR := @HOUR + 1) AS HOUR, (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @HOUR) AS COUNT
FROM ANIMAL_OUTS
WHERE @HOUR < 23
```
