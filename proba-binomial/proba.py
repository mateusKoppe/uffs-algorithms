from math import factorial

def calc_combinacao(n, x):
    return factorial(n)/(factorial(n-x)*factorial(x))

def binomial(n, x, p):
    q = 1 - p
    fatorialC = calc_combinacao(n, x)
    return fatorialC*(p ** x)*(q ** (n-x))

def binomial_acc(n, x, p):
    i = 0
    acc = 0
    while (i <= x):
        acc += binomial(n, i, p)
        i += 1
    return acc

def main():
    n = int(input("Informe n: "))
    x = int(input("Informe x: "))
    p = float(input("Informe o valor absoluto de p: "))
    
    acc = False
    if (input("Acumulativo: [S/n] ") != "n"):
        acc = True

    proba = 0
    if (acc):
        print("to true")
        proba = binomial_acc(n, x, p)
    else: 
        proba = binomial(n, x, p)


    print("O probabilidade é {:.4f}".format(proba))


main()