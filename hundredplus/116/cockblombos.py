
def study(i,block,results):
    total = 0
    total += results[i-block]
    total += results[i-1]

    return total

def main():
    # Initializing result mode
    results2 = {}
    results2[0] = 1
    results2[1] = 1
    results2[2] = 2
    results2[3] = 3
    results2[4] = 5
    results3 = {}
    results3[0] = 1
    results3[1] = 1
    results3[2] = 1
    results3[3] = 2
    results3[4] = 3
    results4 = {}
    results4[0] = 1
    results4[1] = 1
    results4[2] = 1
    results4[3] = 1
    results4[4] = 2

    for i in range(5,51):
        results2[i] = study(i,2,results2)
        results3[i] = study(i,3,results3)
        results4[i] = study(i,4,results4)
        print([i,results2[i]])
        print([i,results3[i]])
        print([i,results4[i]])
        print(results2[i]+results3[i]+results4[i]-3)

if __name__ == "__main__":
    main()
