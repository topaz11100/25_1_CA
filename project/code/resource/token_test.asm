# 분기 및 함수 테스트용 MIPS 어셈블리 예제
# 초기화
    addi $t0, $zero, 10   # $t0 = 10
    addi $t1, $zero, 20   # $t1 = 20
    addi $t2, $zero, 0    # $t2 = 0 (합 저장용)

# 분기 테스트 (bne)
    bne  $t0, $t1, label1 # $t0 != $t1이면 label1으로 점프

    addi $t2, $t2, 100    # 실행되지 않음 (bne 성공했으므로 점프)

label1:
    add  $t2, $t2, $t0    # $t2 += $t0 (10)

# jal 테스트: 서브루틴 호출
    jal  func             # func 호출하고 return address 저장

    addi $t2, $t2, 1      # func 실행 후 돌아와서 1 추가 (26 됨)

# 무조건 점프 테스트
    j    end              # 프로그램 끝으로 점프

# 서브루틴 정의
func:
    addi $t2, $t2, 5      # $t2 += 5
    jr   $ra              # 호출한 곳으로 복귀

end:
