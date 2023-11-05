use std::env;

#[derive(Debug)]
struct Tag {
    v1: u32,
    v2: u32,
    v3: u32,
    buff: [u8; 64],
}

fn main() {
    let args_v: Vec<String> = env::args().collect();
    // println!("ARGS: {:?}\n", args_v);
    let COUNT_2 = args_v[1].parse::<u32>().unwrap();
    let LOOP_TIMES = args_v[2].parse::<u32>().unwrap();

    let v1_arr_to_find: [u32; 5] = [
        COUNT_2 / 2,
        COUNT_2 / 2 + COUNT_2 / 6,
        COUNT_2 / 2 + COUNT_2 / 5,
        COUNT_2 / 2 + COUNT_2 / 4,
        COUNT_2 / 2 + COUNT_2 / 3,
    ];
    // print!("arr: {:?}\n", v1_arr_to_find);

    let mut v: Vec<Tag> = Vec::with_capacity(COUNT_2.try_into().unwrap());

    // push
    for i in 0..COUNT_2 {
        let t = Tag {
            v1: i,
            v2: i + 1,
            v3: i + 2,
            buff: [(i % 200).try_into().unwrap(); 64],
        };

        // if i == 0 {
        //     print!("tag: {:?}\n", &t);
        // }

        v.push(t);
    }

    // find
    let mut sum: u64 = 0;
    for _ in 0..LOOP_TIMES {
        for v1_to_find in v1_arr_to_find {
            for t in v.iter() {
                if t.v1 == v1_to_find {
                    sum += u64::from(t.v2) + u64::from(t.v3);
                    for b in t.buff {
                        sum += u64::from(b);
                    }
                }
            }
        }
    }

    print!("sum: {}\n", sum);
}
