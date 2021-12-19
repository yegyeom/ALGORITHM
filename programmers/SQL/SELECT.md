# SELECT

**[1. 모든 레코드 조회하기 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59034)**

```sql
SELECT *
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```

<br/>

**[2. 역순 정렬하기 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59035)**

```sql
SELECT NAME, DATETIME
FROM ANIMAL_INS
ORDER BY ANIMAL_ID DESC
```

<br/>

**[3. 아픈 동물 찾기 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59036)**

```sql
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION = 'SICK'
ORDER BY ANIMAL_ID
```

<br/>

**[4. 어린 동물 찾기 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59037)**

```sql
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS
WHERE INTAKE_CONDITION != 'Aged'
ORDER BY ANIMAL_ID
```

<br/>

**[5. 동물의 아이디와 이름 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59403)**

```sql
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```

<br/>

**[6. 여러 기준으로 정렬하기 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59404)**

```sql
SELECT ANIMAL_ID, NAME, DATETIME
FROM ANIMAL_INS
ORDER BY NAME, DATETIME DESC
```

<br/>

**[7. 상위 n개 레코드 (Level 1)](https://programmers.co.kr/learn/courses/30/lessons/59405)**

```sql
SELECT NAME
FROM ANIMAL_INS
ORDER BY DATETIME
LIMIT 1
```
