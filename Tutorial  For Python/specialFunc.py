def bolme(no):
    return no/2
#print(bolme(20))
my_list=list(range(1,11))
new_list=[]
for eleman in my_list:
    x=bolme(eleman)
    new_list.append(x)
#print(new_list)

##map
print(list(map(bolme,my_list)))##yukardaki işlemin kolay hali
def check(string):
    return "a" in string#true false döndürecek
print(check("Dark"))
strlist=["dark","masa","ali","veli","zeynep"]
last_list=list(map(check,strlist))
print(list(map(check,strlist)))
print(last_list.count(True))
##filter
print(list(filter(check,strlist)))##değerleri gösterir boolean değil
#lambda
carpma=lambda no:no*3
print(carpma(30))