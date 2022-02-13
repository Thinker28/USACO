def check(s):
    l = len(s)//2
    st = ""
    for i in range(0, l):
        st += s[i]
    st2 = ""
    for i in range(l, len(s)):
        st2 += s[i]
    if st == st2:
        return True
    else:
        return False
n = int(input())
for i in range(n):
    string = input()
    if check(string):
        print("YES")
    else:
        print("NO")
