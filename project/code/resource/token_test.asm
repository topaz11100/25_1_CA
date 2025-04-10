main:   add $t0, $t1, $t2     # $t0 = $t1 + $t2
        sub $s0, $s1, $s2     # $s0 = $s1 - $s2
        and $a0, $a1, $a2     # R-type 기본 연산
        sll $t1, $t2, 3       # shift left logical
        srl $t2, $t1, 2       # shift right logical
        addi $t0, $t1, 10     # $t0 = $t1 + 10
        ori $s1, $s2, 15      # $s1 = $s2 | 15
        lw $t0, 4($sp)        # load word
        sw $t0, 8($sp)        # store word
        beq $t0, $zero, main  # if $t0 == 0, jump to main
        bne $s0, $s1, exit    # if $s0 != $s1, jump to exit
        lui $a0, 100          # load upper immediate
        j middle              # jump to middle
        jal func              # jump and link
middle: xor $t0, $t0, $t0     # clear $t0
        jr $ra                # return
func:   slt $t1, $t2, $t3     # $t1 = ($t2 < $t3)
        nor $s0, $s1, $s2     # $s0 = ~($s1 | $s2)
        j exit
exit:   or $v0, $v0, $zero    # just end
