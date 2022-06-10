# programmers Level 2: 전화번호 목록
# date: 2022-06-11
def solution(phone_book):
    answer = True
    
    phone_book.sort()
    str = phone_book[0]
    
    for i in range(1, len(phone_book)):
        if str == phone_book[i][0:len(str)]:
            answer = False
            break
        else: str = phone_book[i]
        
    return answer