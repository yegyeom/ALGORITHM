# String, Date

**[1. 루시와 엘라 찾기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59046)**

```sql
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty')
ORDER BY ANIMAL_ID
```

<br/>

**[2. 이름에 el이 들어가는 동물 찾기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59047)**

```sql
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME LIKE '%el%' and ANIMAL_TYPE = 'Dog'
ORDER BY NAME
```

<br/>

**[3. 중성화 여부 파악하기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59409)**

```sql
SELECT ANIMAL_ID, NAME,
    CASE
        WHEN SEX_UPON_INTAKE = 'Neutered Male' THEN "O"
        WHEN SEX_UPON_INTAKE = "Spayed Female" THEN "O"
        ELSE "X"
    END AS '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```

<br/>

**[4. 오랜 기간 보호한 동물(2) (Level 3)](https://programmers.co.kr/learn/courses/30/lessons/59411)**

```sql
SELECT A.ANIMAL_ID, B.NAME
FROM ANIMAL_INS A, ANIMAL_OUTS B
WHERE A.ANIMAL_ID = B.ANIMAL_ID
ORDER BY B.DATETIME - A.DATETIME DESC
LIMIT 2
```

<br/>

**[5. DATETIME에서 DATE로 형 변환 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59414)**

```sql
SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') as 날짜
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```
