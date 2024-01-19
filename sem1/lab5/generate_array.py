import random


array = [str(random.randint(-1000000, 1000000)) for _ in range(100000)]

with open("numbers_big.txt", "w") as f:
    f.write(", ".join(array))
    f.write("\n")

