mix_list=[1,2,3.5,"dark",9]
print(type(mix_list))
nestedList=[1,2,3.5,"dark",9,[6,"z"]]
for i in range(0,len(nestedList)):
    print(nestedList[i],end=" ")
    i+=1
print()
print(nestedList[5][1])