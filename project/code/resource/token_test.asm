# 함수 호출 테스트: 1부터 10까지 합을 sum 함수에서 계산하여 $s0에 저장

main:
    addi $a0, $zero, 1     # $a0 = 시작값 1
    addi $a1, $zero, 10    # $a1 = 끝값 10
    jal sum                # sum 함수 호출
    add  $s0, $v0, $zero   # 결과를 $s0에 저장
    sw   $s0, 0($zero)     # 메모리 0번지에 결과 저장
    j end                  # 종료

# sum 함수: $a0부터 $a1까지 정수 합을 계산, 결과는 $v0에 저장
sum:
    addi $sp, $sp, -8      # 스택 공간 확보
    sw   $ra, 4($sp)       # $ra 백업
    sw   $a0, 0($sp)       # $a0 백업

    add  $t0, $a0, $zero   # 현재 값 ← 시작값
    add  $t1, $a1, $zero   # 마지막 값 ← 끝값
    addi $v0, $zero, 0     # 누적합 초기화

loop:
    add  $v0, $v0, $t0     # 누적합 += 현재 값
    addi $t0, $t0, 1       # 현재 값 += 1
    slt  $t2, $t0, $t1     # $t2 = ($t0 < $t1)
    beq  $t2, $zero, exit  # $t0 >= $t1이면 탈출
    j loop                 # 그렇지 않으면 계속
            
exit:
    lw   $a0, 0($sp)       # $a0 복원
    lw   $ra, 4($sp)       # $ra 복원
    addi $sp, $sp, 8       # 스택 복원
    jr   $ra               # 호출 함수로 복귀

end:
    j end                  # 무한 루프 (종료 지점)
