"""def total(*args):#tek tek tüm terimleri yazmak yerine *args yazmak daha mantıklı
    return sum(args)
print(total(10,20,30,40,60))
def func2(*args):
    return args
print(func2(1,2,3,45,6,7))
print(type(func2(1,2,3,45)))
def func3(**kwargs):#keywordslerler kullanırken terimleri tek tek yazmamak için
    return kwargs
print(func3(muz=100,elma=200,ananas=300))
print(type(func3(muz=100,elma=200,ananas=300)))"""
def keywordsCheck(**kwargs):
    if "dark" in kwargs:
        print("dark is here")
    else:
        print("Not here")
print(keywordsCheck(dark=50,ali=70,mehmet=80))