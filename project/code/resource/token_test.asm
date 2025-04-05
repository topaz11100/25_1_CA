# test
test:
addi $t0, $s0, 5 # t0 = 5 
label:
addi $t1, $zero, 10 # t1 = 10 
add $t2, $t0, $t1
end:
sw $t9, 9($s0)