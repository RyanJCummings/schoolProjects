PROGRAM makeChange
IMPLICIT NONE

! Program input is 1-99 cents from console
! Applies greedy algorithm to make change showing how many of each type of coin
! Output to console


INTEGER :: i, quarters, nickels, dimes, pennies
i = 0
quarters = 0
nickels = 0
dimes = 0
pennies = 0

WRITE(*,*) "Please enter an integer between 1 and 99. "
READ(*,*) i

!Check Quarters
IF (mod(i, 25) == 0) THEN
    quarters = (i / 25)
    i = 0
ELSE
    DO WHILE(i > 25)
        i = i - 25
        quarters = quarters + 1
    END DO
END IF

!Check Dimes
IF (mod(i, 10) == 0) THEN
    dimes = (i / 10)
    i = 0
ELSE
    DO WHILE (i > 10)
        i = i - 10
        dimes = dimes + 1
    END DO
END IF

!Check Nickels
IF (mod(i, 5) == 0) THEN
    nickels = (i / 5)
    i = 0
ELSE
    DO WHILE (i > 5)
        i = i - 5
        nickels = nickels + 1
    END DO
END IF

!Check Pennies
DO WHILE (i > 0)
    i = i - 1
    pennies = pennies + 1
 END DO

WRITE(*,*) quarters, " Quarter"
WRITE(*,*) dimes, " Dime"
WRITE(*,*) nickels, " Nickel"
WRITE(*,*) pennies, " Penny"


END PROGRAM
