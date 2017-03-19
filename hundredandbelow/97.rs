//use std::error::Error;
//use std::env;
//use std::f64;
//use std::num;

fn base(digits : u64) -> (u64,usize) {
    let limit = digits as f64-1.0;
    let mut init : u64 = 28433u64;
    let mut counter : usize = 0;
    if (init as f64).log10().floor() > limit {
        init = init % 10u64.pow(digits as u32);
    } else {
        while (init as f64).log10()<limit { 
            init *= 2u64;
            counter += 1;
        }
    }
    (init,counter)
}

fn next_digits( visited : &mut Vec<u64>, limit : u64, multip : u64, repetitions : u32 ) -> bool {
    let mut next_val : u64 = (*visited.last().expect("Digit vector empty."))*multip % limit;
    for encore in 0..repetitions {
        next_val = next_val*multip % limit;
    }
    let place = visited.iter().position(|&x| x == next_val).unwrap_or(visited.len());
    if place==visited.len() {
        visited.push( next_val );
        return true;
    }
    visited.push( place as u64 );
    false
}

fn trim( known : u64, two_exp : u32, limit : u64 ) -> u64 {
    let mut grower = known;
    for i in 0..(two_exp/25 as u32) {
        grower = grower*2u64.pow(25) % limit;
    }
    grower*2u64.pow(two_exp%25) % limit
}

fn main() {
    let digits = 10;
    let repetitions = 500;
    let multip_exp = 25*repetitions;
    let limit : u64 = 10u64.pow(digits);
    let multip : u64 = 2u64.pow(25);

    let mut visited_digits : Vec<u64> = Vec::new();
    // Push initial number
    let (basis, wasted) = base(digits as u64);
    visited_digits.push( basis );

    while next_digits( &mut visited_digits, limit, multip, repetitions-1 ) {
        //println!(" {} {}",*visited_digits.last().unwrap(),visited_digits.len());
    }

    let starter : usize = *visited_digits.last().unwrap() as usize;
    let twos : usize = 7830457 - wasted;
    let remainder = twos/multip_exp as usize - starter;
    let two_exp = (twos as u32)%multip_exp;
    let period = visited_digits.len() - 1 - starter;
    let last_pos = remainder%period;
    println!("{} {}",trim(visited_digits[starter+last_pos],two_exp,limit)+1,period*multip_exp as usize);
    println!("{} {}",std::u64::MAX,multip);
}
