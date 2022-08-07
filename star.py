import sys
entirePattern =["*","* *","*****"]

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

starPrint(24)

