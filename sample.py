def deltaT(tuple):
    prevtime = tuple[0]
    aftertime = tuple[1]

    prevtime = prevtime.split(":")
    aftertime = aftertime.split(":")

    t1 = int(prevtime[0]) * 60 + int(prevtime[1])
    t2 = int(aftertime[0]) * 60 + int(aftertime[1])
    return t2 - t1
print(deltaT(("4:12","4:18")))
[("4:12","4:18"),("4:12","4:18"),("4:12","4:18"),("4:12","4:18")]