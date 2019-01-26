PROGRAM makeChange
IMPLICIT NONE

! Program input is 1-99 cents from console
! Applies greedy algorithm to make change showing how many of each type of coin
! Output to console


integer :: amount, secondAmount, answer
amount = 4
secondAmount = 3

answer = mod(amount, secondAmount)

WRITE(*,*)ANSWER


END PROGRAM
