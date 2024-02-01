from cs50 import get_float
import math
# prompt for amount of change owed
while True:
    change = get_float("Change: ")
    if change > 0:
        break

change = change * 100

# calclutale number of quarters to give costumer
quarters = math.floor(change / 25)
change = change - quarters * 25

# calclutale number of dimes to give costumer
dimes = math.floor(change / 10)
change = change - dimes * 10

# calclutale number of nickles to give costumer
nickels = math.floor(change / 5)
change = change - nickels * 5

# calclutale number of pennies to give costumer
pennies = math.floor(change / 1)
change = change - pennies * 1

# sum coins
coins = quarters + dimes + nickels + pennies

# print total number of coins to give the costumer
print(math.floor(coins))
