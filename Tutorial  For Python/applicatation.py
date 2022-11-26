a=int(input("Enter first num: "))
b=int(input("Enter second num: "))
operate=input("Choose operation: + - * /: ")
def calculate(a,b,operate):
    if operate=='+':
        return print(str(a)+" + "+str(b) + " = " + str(a+b))
    elif operate=='-':
        return print(str(a) + " - " + str(b) + " = " + str(a - b))
    elif operate=='*':
        return print(str(a) + " * " + str(b) + " = " + str(a * b))
    elif operate =="/":
        return print(str(a) + " / " + str(b) + " = " + str(a / b))
calculate(a,b,operate)