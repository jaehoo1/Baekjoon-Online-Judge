어디선가 주워오는 python 메서드/잡기술 등등  

eval(str) : 4+3*1 같은 형태의 문자열을 계산기처럼 계산한다.  
ex : 2408번 문제  
```
s=''
for _ in range(int(input())*2-1):
	s+=input()
print(eval(s.replace('/','//')))
```
  
ord(char) : 문자의 유니코드 값을 return 한다.  
ex : 11283번 문제  
```
A=ord(input())
print(A-44031)
```
