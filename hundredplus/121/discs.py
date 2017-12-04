
prevstatus = {0:1}
blues = 1
reds = 1
blueways = 1
redways = 1

rounds = 15
for round in range(rounds):
    currstatus = {0:0}
    for stat in prevstatus:
        if stat not in currstatus:
            currstatus[stat] = 0
        currstatus[stat] += prevstatus[stat]*redways
        if stat+1 not in currstatus:
            currstatus[stat+1] = 0
        currstatus[stat+1] += prevstatus[stat]*blueways
    prevstatus = currstatus
    redways += 1
    print(prevstatus)

allways = 0
blueways = 0
rper2 = rounds//2
for a in prevstatus:
    allways += prevstatus[a]
    if a > rper2:
        blueways += prevstatus[a]
print(allways,blueways,divmod(allways,blueways))
