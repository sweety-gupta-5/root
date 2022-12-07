import enchant
dictionary = enchant.Dict("en_US") #also available are en_GB, fr_FR, etc
message = 'sdu' #encrypted message
# abcdefghijklmnopqrstuvwxyz
for key in range(1,27):
    # print(key)
    str = message
    ct = ""
    for x in str:
        if(x!=' '):
            y = ord(x) + key
            if y>122 :
                y = y-26
            x = chr(y)
        ct+=x
    print(ct)
    ctlist = ct.split(' ')
    flag = 0
    for x in ctlist:
        if dictionary.check(x)==False :
            flag =1 
    if flag ==0 :print(ct)