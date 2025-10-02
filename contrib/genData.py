import random

n = 10000000

with open("7test.alt.input", "w") as f:
    f.write(str(n))
    f.write("\n")
    for _ in range(n):
        f.write(str(random.gauss()))
        f.write(" ")
