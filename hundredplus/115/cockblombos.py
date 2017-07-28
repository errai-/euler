
def study(i,m,results):
    total = 0
    corner = 0
    news = 1
    for j in range(m,i-m):
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
    m = 50
    results[m] = [2,1]
    results[m+1] = [4,2]

    for i in range(m+2,10*m):
        results[i] = study(i,m,results)
        print([i,results[i][0]])

if __name__ == "__main__":
    main()
