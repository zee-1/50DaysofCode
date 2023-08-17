def count_occurrences(parr, p):
    count = 0
    mark = 4*(10**4)
    for i in range(len(parr)):
        num = abs(parr[i])  # Take the absolute value in case of negative numbers
        if 0 < (num%mark) <= p:
            parr[(num-1)%mark] += mark
    print(parr)  
    for i in range(len(parr)):
        num = parr[i] // mark
        count = num
        parr[i] = count

    return parr

print(count_occurrences([2,3,2,3,5],5))