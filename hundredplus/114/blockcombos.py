
def study(i,results):
    total = 0
    corner = 0
    news = 1
    for j in range(3,i-3):
        news += results[j][1]
    corner += results[i-1][1]
    total += 2*corner
    corner += news
    total += news
    total += results[i-2][0]

    return [total,corner]

def main():
    # Initializing result mode
    results = {}
    results[3] = [2,1]
    results[4] = [4,2]

    for i in range(5,51):
        results[i] = study(i,results)
        print(results[i])

if __name__ == "__main__":
    main()
