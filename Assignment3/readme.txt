1.執行方式：

byacc -vd 101062113_hw3.y
flex 101062113_hw3.l
gcc lex.yy.c y.tab.c symbol.c -lfl


./a.out < test1.c
./a.out < test2.c

result在 andes.s 中

2.gdb：

nds32le-elf-gcc andes.s -Wa,-g -static -o andes.adx
nds32le-elf-gdb andes.adx -tui

(gdb) target sim
(gdb) load
(gdb) b main
(gdb) run
(gdb) next





