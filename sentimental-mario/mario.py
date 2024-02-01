# import get_int from cs50
from cs50 import get_int

# prompt user for hight of pyramid between 1 - 8.
# while true check if value is between 1 - 8.
while True:
    height = get_int("Height: ")
    # if ture break, else prompt again
    if height > 0 and height < 9:
        break

# in a loop go through each line and print the appropirate number of # with a space of 2 between the pyramids.
for row in range(height):
    print(" " * (height-row-1), end="")
    print("#" * (row+1), end="")
    print("  ", end="")
    print("#" * (row+1), end="")
    print()
