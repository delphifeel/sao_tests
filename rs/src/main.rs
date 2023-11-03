const COUNT: u32 = 99999999;

struct Tag {
    v1: u32,
    v2: u32,
    v3: u32,
    v4: u64,
    // buff: [char; 128],
}

impl Tag {
    fn new(i: u32) -> Tag {
        Tag {
            v1: i * 2,
            v2: i * 3,
            v3: i * 4,
            v4: 0,
        }
    }
}

fn tag_same(tag1: &Tag, tag2: &Tag) -> bool {
    if tag1.v1 != tag2.v1 {
        return false;
    }
    if tag1.v2 != tag2.v2 {
        return false;
    }
    if tag1.v3 != tag2.v3 {
        return false;
    }
    return true;
}

fn main() {
    let mut v: Vec<Tag> = Vec::with_capacity(COUNT.try_into().unwrap());

    // push
    for i in 0..COUNT {
        let t = Tag::new(i);
        v.push(t);
    }

    // find
    let tag_to_find = Tag::new(COUNT / 2);
    for t in v {
        if tag_same(&t, &tag_to_find) {
            println!("We found it");
        }
    }
}
