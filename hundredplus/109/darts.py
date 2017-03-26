import operator

class Holder:
    def __init__(self):
        self.vals = {}
        self.doubles = []
        self.filler()

    def counter(self, nro):
        count = 0

        count += self.ones(nro)
        count += self.twos(nro)
        count += self.threes(nro)

        return count

    def ones(self,nro):
        if nro in self.doubles:
            return 1
        return 0

    def twos(self,nro):
        count = 0

        for endgame in self.doubles:
            tru_nro = nro - endgame
            if tru_nro < 1:
                break
            if tru_nro in self.vals:
                count += self.vals[tru_nro]

        return count

    def threes(self,nro):
        count = 0

        for endgame in self.doubles:
            tru_nro = nro - endgame
            if tru_nro < 1:
                break

            for num in self.vals:
                remain = tru_nro - num
                if remain < num:
                    continue
                if remain in self.vals:
                    if remain == num:
                        count += (self.vals[num]+1)*self.vals[num]/2
                    else:
                        count += self.vals[remain]*self.vals[num]

        return count

    def filler(self):
        for i in range(1,21):
            if i in self.vals:
                self.vals[i] += 1
            else:
                self.vals[i] = 1
            double = 2*i
            self.doubles.append(double)
            if double in self.vals:
                self.vals[double] += 1
            else:
                self.vals[double] = 1
            triple = 3*i
            if triple in self.vals:
                self.vals[triple] += 1
            else:
                self.vals[triple] = 1
        self.vals[25] = 1
        self.vals[50] = 1
        self.doubles.append(50)


def main():

    jaa = Holder()
    count = 0
    for i in range(1,100):
        count += jaa.counter(i)
    print count

if __name__ == "__main__":
    main()
