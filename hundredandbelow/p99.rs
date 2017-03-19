use std::io::prelude::*;
use std::fs::File;
use std::error::Error;
use std::path::Path;
use std::env;


fn main() {
    let args: Vec<_> = env::args().collect();

    // Try to obtain input file name from command line params.
    if args.len() < 2 {
        println!("Insert data file name as a command line parameter");
        return; 
    }
    let path = Path::new(&args[1]);
    let display = path.display();

    // Open file and read it to a string
    let mut file = match File::open(&path) {
        Err(why) => panic!("could not open {}: {}", display, Error::description(&why)),
        Ok(file) => file,
    };
    let mut data = String::new();
    match file.read_to_string(&mut data) {
        Err(why) => panic!("could not read {}: {}", display, Error::description(&why)),
        Ok(_) => {},
    }

    let mut line_count = 0;
    let mut maximum : f64 = 0.;
    let mut max_line = 0;
    for line in data.lines() {
        line_count += 1;
        let value: Vec<&str> = line.split(",").collect();
        
        let base = match value[0].parse::<u64>() {
            Err(why) => panic!("non-numeric data {}",Error::description(&why)),
            Ok(base) => base,
        };
        let exp = match value[1].parse::<u64>() {
            Err(why) => panic!("non-numeric data {}",Error::description(&why)),
            Ok(exp) => exp,
        };

        let number = (exp as f64)*(base as f64).log10();
        if number > maximum {
            maximum = number;
            max_line = line_count;
        }
    }
    println!("{} {}",max_line,maximum);
}
