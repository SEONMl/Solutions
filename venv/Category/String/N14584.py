import sys;input=sys.stdin.readline
encrypt_code=input().strip()
N=int(input())
words=[input().strip() for i in range(N)]
def check():
    for i in range(26):
        decryption=''
        for j in encrypt_code:
            cur=(ord(j)-97+i)%26+97
            decryption+=chr(cur)
        for word in words:
            if word in decryption:
                return decryption
print(check())