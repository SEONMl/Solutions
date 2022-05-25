# w,h 1억 이하 자연수
# w==h : w*h-w
# 최대공약수?
def solution(w,h):
    return w*h-(w+h-gcd(w,h))
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)