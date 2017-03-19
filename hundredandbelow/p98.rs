#![feature(collections)]
use std::io::prelude::*;
use std::fs::File;
use std::error::Error;
use std::path::Path;
use std::env;
use std::string::String;

struct Anagrams {
    holder: Vec<String>,
    abstract_order: Vec<String>,

    word_len: usize,
}

impl Anagrams {
    fn new(ana: &str)->Anagrams {
        let mut hold_start = Vec::new();
        hold_start.push(String::from_str(&ana));
        Anagrams {
            holder: hold_start,
            abstract_order: Vec::new(),

            word_len: ana.len(),
        }
    }

    fn add(&mut self, ana: &str) {
        let addition = String::from_str(&ana);
        if !self.holder.contains(&addition) {
            self.holder.push(addition);
        }
    }

    fn abstraction(&mut self) {
        for word in self.holder.iter() {
            let mut utilized: Vec<char> = Vec::new();
            let mut add_word = String::new();
            for digit in word.chars().rev() {
                let pos: Option<usize> = if utilized.contains(&digit) {
                    utilized.position_elem(&digit)
                } else {
                    utilized.push(digit);
                    Some(utilized.len()-1)
                };
                add_word.push( ( (pos.expect("The world is burning, run!")+48) as u8) as char );
            }
            self.abstract_order.push( add_word );
        }
    }
}

struct Squares {
    squares: Vec<Vec<u64>>,
    abstract_order: Vec<Vec<String>>,
}

impl Squares {
    fn new()->Squares {
        let mut vecs: Vec<Vec<u64>> = Vec::new();
        let mut abstracts: Vec<Vec<String>> = Vec::new();
        for i in 0..8 {
            vecs.push(Vec::new());
            abstracts.push(Vec::new());
        }
        let mut unsquared: u64 = 4;
        loop {
            let square = unsquared.pow(2);
            let tier: usize = (square as f64).log10().floor() as usize - 1;
            if tier > 7 { break; }
            vecs[tier].push( square );
            abstracts[tier].push( number_abstraction( square) );
            unsquared += 1;
        }
        Squares {
            squares: vecs,
            abstract_order: abstracts,
        }
    }

}

fn number_abstraction(mut num: u64)->String {
    let mut word = String::new();
    let mut utilized = Vec::new();
    while num!=0 {
        let digit = num%10;
        let pos = if utilized.contains(&digit) {
            utilized.position_elem(&digit)
        } else {
            utilized.push(digit);
            Some(utilized.len()-1)
        };
        word.push( ( (pos.expect("The wordl is burning, run!")+48) as u8) as char );
        num = num/10;
    }
    word
}

fn numbers(mut num: u64, characters: String)->String {
    let mut word = String::new();
    let mut utilized = Vec::new();
    let char_helper: Vec<char> = characters.chars().rev().collect();
    let mut idx = 0;
    while num!=0 {
        utilized.push( ((num%10+48) as u8,char_helper[idx]) );
        num = num/10; idx += 1;
    }
    utilized.sort_by(|a,b| (&a.0).cmp(&b.0));
    for digit in utilized.iter() {
        word.push( digit.0 as char );
        word.push( digit.1 );
    }
    word
}

fn to_order(word: &str) -> String {
    let mut result: String = String::new();
    let mut order: Vec<char> = word.chars().collect();
    order.sort();
    for chr in order {
        result.push(chr);
    }
    result
}

fn main() {
    let path = Path::new("p098_words.txt");
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

    // Place data into anagram holders
    let mut identification: Vec<String> = Vec::new();
    let mut anagrams: Vec<Anagrams> = Vec::new();
    for word in data.trim_matches('"').split("\",\"") {
        let identifier = to_order(word);
        if !identification.contains(&identifier) {
            anagrams.push(Anagrams::new(word));
            identification.push(identifier);
        } else {
            anagrams[ identification.position_elem(&identifier).unwrap() ].add(word);
        }
    }

    // Delete words with no anagrams
    let mut idx = 0;
    while idx < anagrams.len() {
        if anagrams[idx].holder.len()<2 {
            anagrams.remove(idx);
        } else {
            anagrams[idx].abstraction();
            idx += 1;
        }
    }

    let squares: Squares = Squares::new();
    for jaa in anagrams.iter() {
        if jaa.word_len<10 {
        let mut first: Vec<(u64,String)> = Vec::new();
        for juu in 0..jaa.holder.len() {
            for i in 0..squares.squares[jaa.word_len-2].len() {
                if squares.abstract_order[jaa.word_len-2][i]==jaa.abstract_order[juu] {
                    let square_cand1 = jaa.holder[juu].clone();
                    let square = squares.squares[jaa.word_len-2][i].clone();
                    let cipher = numbers(square,square_cand1);
                    //println!("{}",cipher);
                    if juu==0 {
                        first.push((square,cipher));
                    } else {
                        for jes in first.iter() {
                            if jes.1==cipher {
                                println!("Number: {} {}",jaa.holder[juu],jaa.abstract_order[juu]);
                                println!("        {} {} {}",jes.0,square,jaa.holder[juu]);
                            }
                        }
                    }
                }
            }
        }
        }
    }
}
