# 220508 | 정수론, 유클리드 호제법(반복문, 재귀)
'''
임의의 두 자연수 a, b가 주어 졌을 때. 둘중 큰 값이 a라고 가정해 보겠습니다.
a를 b로 나눈 나머지를 n 이라고 하면 (a%b = n)
n이 0일때, b가 최대 공약수(GCD)입니다.
만약 n이 0이 아니라면, a에 b값을 다시 넣고 n를 b에 대입 한 후 다시 위에 step2부터 반복하면 됩니다.
'''
n=int(input())
# Greatest Common Division
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
# Least Common Multiple | 최소공배수 = a * b / 최대공약수
def lcm(a,b):
    return a*b//gcd(a,b)

for _ in range(n):
    a,b=map(int,input().split())
    print(lcm(a,b))