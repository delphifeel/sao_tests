cc -DCORE_SET_UNSAFE_RELEASE -O2 -o main_c_unsafe main.c
cc -O2 -o main_c main.c
cc -O2 -o main_cptrs main_ptrs.c

echo "[C Unsafe Release] Vector of structs"
time ./main_c_unsafe

echo "[C] Vector of structs"
time ./main_c

#echo "[C] Vector of ptrs"
#time ./main_cptrs

cd rs
cargo build -r
cd ..
echo "[Rust] Vector of structs"
time ./rs/target/release/rs

zig build-exe main.zig -I. -OReleaseFast
echo "[Zig] Vector of structs"
time ./main

go build -o main_go main.go
echo "[Go] Vector of structs"
time ./main_go
