#!/usr/bin/python3

#, setcheckinterval
#setcheckinterval(10000000)
            
"""def merge(decks, dicto):
    # SKRIV DIN KODE HER
    # res=decks
    # res.append(decks);
    _IE=IndexError
    while (1):
        i = 0
        temp=[]
        #temp=list(map(merge2(decks[2*i],decks[2*i+1]) for i in range(int(lengde/2))))
        while True:
            try:
                temp.append(merge2(decks[i], decks[i + 1]));
                # decks[i]=res[:]
                i += 2
            except _IE:
                try:
                    temp.append(decks[i])
                except _IE:
                    pass;
                break;

        decks = temp
        try:
            decks[1]
        except IndexError:
            break
    # return "".join(res[c][0][1])
    slist = [dicto[x] for x in decks[0]]
    print("".join(slist))"""


def merge2(d1, d2):
    i1 =i2=0
    res=[9999999999]*(len(d1)+len(d2)-1)
    r=len(res)
    current1=d1[0]
    current2=d2[0]
    for index in range(r-1):
        if current1 < current2:
            res[index] = current1
            i1 += 1
            # index+=1
            current1 = d1[i1]
        else:
            res[index] = current2
            i2 += 1
            # index+=1
            current2 = d2[i2]
        """try:

        except:
            while 1:
                try:
                    res[i1+i2] = d2[i2]
                    i2 += 1
                except:
                    break#return res
            while 1:
                try:
                    res[i1+i2] = d1[i1]
                    i1 += 1
                except:
                    break#return res
            break"""
    #res.append(9999999999)
    return res#[(l1+l2):]

def main():
    from sys import stdin
    #from itertools import repeat
    # Read input.
    _map = map
    dicto = {}
    #fp = os.open("input.txt", os.O_RDWR)
    #os.read(fp, 1)
    # decks=list(
    #fp = open("input.txt",'r')
    decks=[]
    ud=dicto.update
    for line in stdin:
        _int = int
        (index, csv) = line.strip().split(":")
        it=csv.split(",")
        nums = list(_map(_int, it))
        #nums=[int(x) for x in f]
        #nums=[int(x) for x in csv.split(",")]
        #nums = list(map(_int, map(float,csv.split(','))))
        #nums=[_int(x,10) for x in csv.split(',')]
        ud(dict.fromkeys(nums, index))  # =dict(dicto,**dict.fromkeys(nums,index))
        #decks= decks+[(nums)]
        decks.append(nums)
    # Merge the decks and print result.
    #merge(decks, dicto)
    #decks=merge(decks, 0, len(decks)-1)
    for deck in decks:
        if(len(deck)>2500):
            raise IndexError;
        deck.append(9999999999)

    #lewps = (len(decks) + 1) // 2
    r=2
    for i in range(8):
        i = 0
        r = len(decks)
        # temp=list(map(merge2(decks[2*i],decks[2*i+1]) for i in range(int(lengde/2))))
        temp = [merge2(decks[2 * aa], decks[2 * aa + 1]) for aa in range(r // 2)]
        """for aa in range(r // 2):
            app(merge2(decks[2 * aa], decks[2 * aa + 1]));
            i = aa"""
        # if (r//2)*2!=r:
        if (r % 2 == 1):
            temp.append(decks[-1])

        decks = temp
    # return "".join(res[c][0][1])"""
    res=decks[0]
    if(len(res)>48000):
        raise IndexError;
    dicto[9999999999]=''
    slist = [dicto[x] for x in res]
    print("".join(slist))

if __name__ == "__main__":
    main()
