##range
"""my_list=list(range(16))#0-15 a ya kadar liste olusturur
print(my_list)
my_list2=list(range(5,22,4))
print(my_list2)"""
#enumerate
"""index=0
for num in list(range(5,15)):
    print(f"Güncel no: {num} güncel index{index}")
    index+=1"""
"""for num2 in enumerate(list(range(5,15))):
    print(num2)#değerleri index-değer şeklinde yazdırır"""
"""for (index,no) in enumerate(list(range(5,15))):
    print(index,end=" ")"""

##random
"""from random import *
print(randint(15,21))#aralıkta rastgele çıktı verir
new_list=list(range(0,10))
print(new_list[randint(0,9)])
shuffle((new_list))#listeyi karıstırır
print((new_list))"""
##zip
"""food={"banana","ananas","apple"}
calori=list(range(100,400,100))
day=["mon","tue","wed"]
print(list(zip(food,calori,day)))"""
##ileri seviye listeler
listeornek=[]
mystring="Dark was Here"
for harf in mystring:
    listeornek.append(harf)
print(listeornek)