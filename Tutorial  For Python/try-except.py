
def calculate(a,b,operate):
    if operate not in "+-*/":
        return  print("Please choose one of them +-*/")
    if operate=='+':
        return print(str(a)+" + "+str(b) + " = " + str(a+b))
    elif operate=='-':
        return print(str(a) + " - " + str(b) + " = " + str(a - b))
    elif operate=='*':
        return print(str(a) + " * " + str(b) + " = " + str(a * b))
    elif operate =="/":
        return print(str(a) + " / " + str(b) + " = " + str(a / b))
while True:
    try:
        a=int(input("Enter first num: "))
        b=int(input("Enter second num: "))
        operate=input("Choose operation: + - * /: ")
        calculate(a,b,operate)
    except:
        print("Please enter the just integer")