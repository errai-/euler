
struct GenNumber {
    primes: Vec<u64>,
    prime_probe: u64,

    m: u64,
    ml: u64,
    n: u64,
    nl: u64,

    limit: u64,
}

impl GenNumber {
    fn new()->GenNumber {
        GenNumber {
            primes: Vec::new(),
            prime_probe: 3,

            m: 1,
            ml: 1,
            n: 1,
            nl: 1,

            limit: 1,
        }
    }

    fn glorious_inspector( &mut self, mum: u64, num: u64 ) -> bool {
        self.m = mum;
        self.ml = mum-1;
        self.n = num;
        self.nl = num-1;

        if !self.two_inspector() { return false; }

        self.limit = (self.n as f64).sqrt().floor() as u64;
        self.primes_until();

        if !self.full_inspector() { return false; }
        true
    }

    fn two_inspector( &mut self ) -> bool {
        let mut storage = 0;
        while self.n%2==0 { self.n = self.n/2; storage += 1; }
        while self.nl%2==0 { self.nl = self.nl/2; storage +=1; }
        while self.m%2==0 { self.m = self.m/2; storage -= 1; }
        while self.ml%2==0 { self.ml = self.ml/2; storage -= 1; }
        if storage==-1 { return true; }
        false
    }

    fn full_inspector( &mut self ) -> bool {
        for prime in self.primes.iter() {
            if (self.n==1 && self.nl==1) || *prime > self.limit { break; }
            let mut storage = 0;
            while self.n%prime==0 { self.n = self.n/prime; storage += 1; }
            while self.nl%prime==0 { self.nl = self.nl/prime; storage += 1; }
            while self.m%prime==0 { self.m = self.m/prime; storage -= 1; }
            while self.ml%prime==0 { self.ml = self.ml/prime; storage -= 1; }
            if storage != 0 { return false; }
        }
        if self.n != 1 {
            if self.m%self.n==0 { self.m=1; }
            else if self.ml%self.n==0 { self.ml=1; }
            else { return false; }
        }
        if self.nl != 1 {
            if (self.m%self.nl != 0) && (self.ml%self.nl != 0) { return false; }
        }
        true
    }

    fn primes_until( &mut self ) {
        while self.prime_probe <= self.limit {
            if self.is_prime() {
                self.primes.push( self.prime_probe );
            }
            self.prime_probe += 2;
        }
    }

    fn is_prime( &self )->bool {
        let limit = (self.prime_probe as f64).sqrt().floor() as u64;
        for divisor in self.primes.iter() {
            if self.prime_probe%divisor==0 { return false; }
            if *divisor > limit  { break; }
        }
        true
    }
}

fn main() {
    let mut probe : f64 = 1000000000000.;

    let root2 : f64 = 2f64.sqrt();
    let mut inspector: GenNumber = GenNumber::new();
    loop {
        probe += 1.;
        if probe==1800000000000. {break}
        let rounded : f64 = (( probe - 0.5f64 )/root2 + 0.5).round();
        let mut diff = probe/root2; diff -= rounded;
        diff += 0.5f64*(1f64-1f64/root2);
        if (probe as u64)%100000000==0 { println!("{}",probe); }
        if diff.abs()<0.0001 {
            if inspector.glorious_inspector( probe as u64, rounded as u64 ) {
                println!("{} {}",probe,rounded);
                break;
            }
        }
    }
}
