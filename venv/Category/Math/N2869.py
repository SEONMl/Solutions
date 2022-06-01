import math
import sys
input=sys.stdin.readline
a,b,v=map(int, input().split())
day=(v-b)/(a-b)
print(math.ceil(day)) # 올림 메서드