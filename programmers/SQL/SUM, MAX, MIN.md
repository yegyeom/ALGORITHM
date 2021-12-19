# SUM, MAX, MIN

**[1. 최댓값 구하기 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59415)**

```sql
SELECT MAX(DATETIME)
FROM ANIMAL_INS
```

<br/>

**[2. 최솟값 구하기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59038)**

```sql
SELECT MIN(DATETIME)
FROM ANIMAL_INS
```

<br/>

**[3. 동물 수 구하기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59406)**

```sql
SELECT COUNT(*)
FROM ANIMAL_INS
```

<br/>

**[4. 중복 제거하기 (Level 2)](https://programmers.co.kr/learn/courses/30/lessons/59408)**

```sql
SELECT COUNT(DISTINCT NAME)
FROM ANIMAL_INS
WHERE NAME IS NOT NULL
```
