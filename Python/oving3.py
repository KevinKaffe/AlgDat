from sys import stdin


def binarySearch(L, v,u):
    l=0
    while(l<=u):
        m=(l+u)>>1
        curr=L[m]
        if curr==v:
            return m
        elif curr>v:
            u=m-1
        else:
            l = m + 1
    return m

def search(L, l,u, maxv):
    il=binarySearch(L,l, maxv)
    iu=binarySearch(L,u, maxv)
    if L[il]>l:
        il-=1
    if L[iu]<u:
        iu+=1
    return (L[il], L[iu])

def main():
    radix=1<<10
    radixMax=radix-1
    arr=[[] for _ in range(radix)]
    for x in map(int,stdin.readline().split(" ")):
        arr[x&radixMax].append(x)
    oldArr=arr
    arr=[[] for _ in range(radix)]
    for ind in oldArr:
        for elem in ind:
            arr[(elem>>10)&radixMax].append(elem)
    oldArr=arr
    arr=[[] for _ in range(radix)]
    for ind in oldArr:
        for elem in ind:
            arr[0].append(elem)
    lengde=len(arr[0])-1
    arr[0].append(arr[0][-1])
    arr[0].append(arr[0][0])
    l=tuple(arr[0])
    textRes=tuple(map(int, stdin.read().split()))
    res=["%s %s\n"%(search(l, textRes[2*i], textRes[2*i+1], lengde)) for i in range(len(textRes)>>1)]
    print("".join(res), end='')

if __name__ == "__main__":
    main()
