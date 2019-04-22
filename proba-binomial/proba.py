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
    calc_interface()

def calc_interface():
    print("======== Calculo de Coeficiente Binomial ========")
    n = int(input("Informe n: "))
    x = int(input("Informe x: "))
    p = float(input("Informe o valor absoluto de p: "))
    
    proba_acc = binomial_acc(n, x, p)
    proba = binomial(n, x, p)


    print("O probabilidade simples é {:.4f}".format(proba))
    print("O probabilidade acumulada é {:.4f}".format(proba_acc))
    menu_interface()

def menu_interface():
    print("======== Calculo de Coeficiente Binomial ========")
    print("[1] - Calcular novamente")
    print("[2] - Sair")
    choice = int(input())
    if (choice == 1):
        calc_interface()

main()
