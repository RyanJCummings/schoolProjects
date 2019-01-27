PROGRAM makeChange
IMPLICIT NONE

! Program input is 1-99 cents from console
! Applies greedy algorithm to make change showing how many of each type of coin
! Output to console


INTEGER :: i, quarters, nickles, dimes, pennies
amount = 4
secondAmount = 3

answer = mod(amount, secondAmount)

print("Please enter an integer between 1 and 99.")
READ(*,*) i




WRITE(*,*)ANSWER


END PROGRAM
