#run on /llvm/code path
PATH=/usr/clang/bin/:$PATH
clang -c -emit-llvm hello.cpp -o hello.bc
llvm-dis hello.bc
opt -dot-cfg -o hello.bc hello.bc
dot -Tfig -O cfg._Z4multv.dot
opt -load /home/cilab/LLVM/build/lib/LLVMHello.so -help | grep opcode
opt -load /home/cilab/LLVM/build/lib/LLVMHello.so -opcount < hello.bc >> /dev/null
