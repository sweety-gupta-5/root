def euclidean(a: int, b: int):
  r1 = a
  r2 = b

  print(f'{"q"} {"r1":>20} {"r2":>20} {"r":>20}')
  print("")

  while r2 != 0:
    q = r1 // r2
    r = r1 - q * r2
    print(f'{q} {"%20.0d" % r1} {"%20.0d" % r2} {"%20.0d" % r}')
    
    r1 = r2
    r2 = r
  
  print(f'{"-"} {"%20.0d" % r1} {"%20.0d" % r2} {"-":>20}')
  
  print(f'GCD({a}, {b}) = {r1}')
  



def main():

  a = int(input('Enter a: '))
  b = int(input('Enter b: '))
  euclidean(a,b)


   

main()  
  
