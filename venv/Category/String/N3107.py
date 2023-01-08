import sys;input=sys.stdin.readline
ipv6=list(map(str,input().rstrip().split(":")))
ip=['0000']*8
cnt=ipv6.count('')
if cnt==0:
    for i in range(8):
        ip[i]=ipv6[i]
else:
    idx=ipv6.index('')
    preIp=ipv6[:idx]
    postIp=ipv6[idx:]
    if cnt==2:
        nextIdx=ipv6.index('',idx+1)
        postIp=ipv6[nextIdx:]

    for i in range(len(preIp)):
        ip[i]=preIp[i]
    for i in range(len(postIp)):
        ip[7-i]=postIp[-1-i]
    
for i in range(len(ip)):
    if(i==len(ip)-1):
        print('{0:0>4}'.format(ip[-1]))
    else:
        print('{0:0>4}:'.format(ip[i]),end="")
'''
처음에 축약
중간에 축약
마지막에 축약
0000:1::
1:2:3:4:5:6:7::
1::22:3:4
'''