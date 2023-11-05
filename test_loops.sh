OPT_LEVEL="-DDO_BUFF_EMBED -O3"
#OPT_LEVEL="-O3"
cc -DCORE_SET_UNSAFE_RELEASE $OPT_LEVEL -o main_loops_unsafe main_loops.c
cc $OPT_LEVEL -o main_loops main_loops.c
cc $OPT_LEVEL -o main_loops_ptrs main_loops_ptrs.c
cc $OPT_LEVEL -o main_loops_soa main_loops_soa.c

# Rust build
cd rs
cargo build -r
cd ..

# Zig Build
zig build-exe main.zig -OReleaseFast -lc

#3 000 000 000
#3000000000

ARGS="50000 30"

echo "[Zig] Loops AOS"
time ./main $ARGS

echo "[C] Loops SOA"
time ./main_loops_soa $ARGS

# echo "[C Unsafe Release] Loops"
# time ./main_loops_unsafe $ARGS

echo "[C] Loops"
time ./main_loops $ARGS

#echo "[C] Loops Ptrs"
#time ./main_loops_ptrs $ARGS

echo "[Rust] Loops AOS"
time ./rs/target/release/rs $ARGS
