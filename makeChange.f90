PROGRAM makeChange
IMPLICIT NONE

! Program input is 1-99 cents from console
! Applies greedy algorithm to make change showing how many of each type of coin
! Output to console


integer :: amount

READ(*,*)amount
WRITE(*,*) amount

END PROGRAM
