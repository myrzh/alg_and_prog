counter = 1
number = 0.13203
digits = []
while counter <= 23:
    # print(f"{number} * 2 = {number * 2}")
    print(f"{counter}) {int(number * 2)} ({round(number * 2, 5)})")
    digits.append(str(int(number * 2)))
    number *= 2
    if number >= 1:
        number -= 1
    counter += 1

print()
print(" ".join(digits))
