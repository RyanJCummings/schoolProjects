num = int(input("Please enter an int between 1 and 99 "))
quarters = 0
dimes = 0
nickels = 0
pennies = 0

if (num % 25 == 0):
    quarters = num / 25
else:
    while (num > 25):
        num = num - 25
        quarters += 1

if (num % 10 == 0):
    dimes = num / 10
else:
    while(num > 10):
        num = num - 10
        dimes += 1

if (num % 5 == 0):
    nickels = num / 5
else:
    while(num > 5):
        num = num - 5
        nickels += 1

while(num > 0):
    num = num - 1
    pennies += 1


print("Quarters: " + str(quarters))
print("Dimes: " + str(dimes))
print("Nickels: " + str(nickels))
print("Pennies: " + str(pennies))
