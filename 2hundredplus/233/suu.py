



for N in range(2,100):
    for b in range(1,N/4):
        suu = N*N-2.0*N*b-b*b
        sqrtsuu = suu**0.5
        if round(sqrtsuu)==sqrtsuu:
            print(N,b,N+b,suu,sqrtsuu)
