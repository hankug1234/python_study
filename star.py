import sys
entirePattern =["*","* *","*****"]
dict = {0:1,1:1}


def check_same_element(s1, s2):
    if len(s1) != len(s2):
        return False
    if len(set(s1) - set(s2)) == 0:
        return True
    return False


def add_in_list(n, d, l, path):
    for x in d[n]:
        new_path = path + " " + x
        check = False
        for y in l:
            if check_same_element(new_path.split(" "), y.split(" ")):
                check = True
                break
        if not check:
            l.append(new_path)


def devide_integer(n, min_v, max_v, path, l, d):
    if n in d:
        add_in_list(n, d[n], l, path)
        return l
    if n == 0:
        l.append(path)
        return l
    if n < min_v:
        return l

    n_l = []
    if n < max_v:
        max_v = n
    for x in range(min_v, max_v + 1):
        devide_integer(n - x, min_v, max_v, str(x), n_l, d)

    d[n] = n_l
    add_in_list(n, n_l, l, path)
    return l


def PI(n, min_v, max_v):
    l = []
    d = {}
    devide_integer(n, min_v, max_v, "", l, d)
    return l

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

