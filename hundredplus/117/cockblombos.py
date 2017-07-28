
def study(i,results):
    total = 0
    total += results[i-2]
    total += results[i-3]
    total += results[i-4]
    total += results[i-1]

    return total

def main():
    # Initializing result mode
    results = {}
    results[0] = 1
    results[1] = 1
    results[2] = 2
    results[3] = 4
    results[4] = 8

    for i in range(5,51):
        results[i] = study(i,results)
        print([i,results[i]])
        print(results[i])

if __name__ == "__main__":
    main()
