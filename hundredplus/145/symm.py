from collections import defaultdict

def checker(num):
    for nam in str(num):
        dig = int(nam)
        if dig%2==0:
            return False
    return True

def strchecker(num):
    for nam in num:
        dig = int(nam)
        if dig%2==0:
            return False
    return True

def reverse(num):
    return int(str(num)[::-1])

def strreverse(num):
    return int(num[::-1])

def symm(head,tail,add,lim,pck):
    nums = 2*(len(tail)+1)
    if nums<=lim:
        print(nums)
        for first in range(add,10+add):
            if nums==2 and first==0: continue
            ovr = (first+1)%2
            for sec in range(ovr,10,2):
                if nums==2 and sec==0: continue
                comb = first+sec
                new = comb%10
                surplus = int(comb/10)
                hiid = 10*head+comb-add
                tiil = str(new)+tail
                symm(hiid,tiil,surplus,lim,pck)

                appendix = hiid+surplus
                if checker(appendix): pck[0] += 1

                if surplus==1 and (nums+1)<=lim:
                    for mid2 in range(1,21,2):
                        newmid = mid2%10
                        surplusmid = mid2/10
                        midhiid = hiid+surplusmid
                        midtiil = str(mid2)+tail
                        if checker(midhiid):
                            pck[0] += 1

pack = [0]
symm(0,"",0,9,pack)
print("hoho",pack)
