main:
    addi $t0, $zero, 10     # $t0 = 10 (i형, 양수 즉시값)
    addi $t1, $zero, -5     # $t1 = -5 (i형, 음수 즉시값)
    add  $t2, $t0, $t1      # $t2 = $t0 + $t1 (r형, 산술)
    
    sll  $t3, $t2, 1        # $t3 = $t2 * 2 (r형, 시프트)
    srl  $t4, $t3, 2        # $t4 = $t3 / 4 (산술 시프트)

    sw   $t4, 0($sp)        # 메모리 저장 (메모리 접근)
    lw   $t5, 0($sp)        # 메모리 로드

    slt  $t6, $zero, $t5    # $t6 = ($zero < $t5)? 1 : 0 (음수 판별)
    beq  $t6, $zero, is_ne  # if $t5 <= 0 jump to is_negative
    j    is_po              # 양수이면 is_positive로 jump

is_ne:
    addi $a0, $zero, 1      # $a0 = 1 (음수 분기 확인용)
    jal  print              # 함수 호출
    j    end                # 종료

is_po:
    addi $a0, $zero, 2      # $a0 = 2 (양수 분기 확인용)
    jal  print       # 함수 호출

print:
    add  $v0, $a0, $zero    # 반환값 세팅
    jr   $ra                # 복귀

end:

