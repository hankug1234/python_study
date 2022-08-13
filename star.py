import sys
entirePattern =["*","* *","*****"]
dict = {0:1,1:1}

def check_same_element(s1,s2):
    if len(s1) != len(s2):
        return False
    if len(set(s1) - set(s2)) == 0:
        return True
    return False

def fabonich(n):
    if(n<0): return print("index error")
    elif(n in dict.keys()): return dict[n]
    else:
        dict[n] = fabonich(n-1) + fabonich(n-2)
        return dict[n]

def nulString(n):
    nul = ""
    for i in range(0,n):
        nul +=" "
    return nul

def function(n1,n2):
    entirePattern.append(entirePattern[n1]+nulString(n2)+entirePattern[n1])

def run(n):
    while(len(entirePattern) <= n):
        l = len(entirePattern)
        for i in range(0,l):
         function(i,len(entirePattern[l-1-i]))

def starPrint(n):
    run(n)
    for i in range(0,n):
        print(nulString(n-1-i)+entirePattern[i]+"\n")

starPrint(96)

