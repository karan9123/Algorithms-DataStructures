def solution(gas, cost):
    remaining = 0
    candidate = 0
    prev_remaining = 0
    for i in range(len(gas)):
        remaining += gas[i] - cost[i]
        if remaining < 0:
            candidate = i+1
            prev_remaining += remaining
            remaining = 0
    if candidate == len(gas) or prev_remaining + remaining < 0:
        return -1
    else:
        return candidate




def main():
    print("Hello")
    gas = [1, 5, 3, 3, 5, 3, 1, 3, 4, 5]
    cost = [5, 2, 2, 8, 2, 4, 2, 5, 1, 2]
    print(solution(gas, cost))




if __name__ == '__main__':
    main()