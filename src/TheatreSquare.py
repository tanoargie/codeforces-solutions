import math

def main():
    nS, mS, aS = map(str,input().split())
    n = int(nS)
    m = int(mS)
    a = int(aS)

    toBottom = math.ceil(n / a)
    toRight = math.ceil(m / a)

    print(toBottom * toRight)

if __name__ == "__main__":
    main()
