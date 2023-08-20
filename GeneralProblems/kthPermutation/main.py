from math import ceil

def factorial(num):
    if num <=1:
        return 1
    else:
        fact = [1]
        for i in range(1, num+1):
            fact.append(fact[i-1] * i)
    return fact[num]

def recursivePerm(arr , perm, final):
    if len(arr) == 1:
            final.append(arr[0])
            return
    else:
        num = len(arr)

        factoria = factorial(num)

        k = ceil(perm / (factoria//num)) -1
        
        removedElem = arr[k]
        final.append(removedElem)
        arr.remove(removedElem)

        recursivePerm(arr,  (perm % (factoria//num)), final)
        


def kthPerm(num, perm):
    factor = factorial(num)
    if factor < perm:
        return -1
    else:
        arr = [i+1 for i in range(num)]
        final = []
        recursivePerm(arr, perm, final)
    return final







def main():
    fact = 4
    perm = 2
    # print(factorial(7))
    print(kthPerm(fact, perm))

if __name__ == '__main__':
    main()