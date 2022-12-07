def multInv(a: int, b: int):
  r1 = a
  r2 = b
  t1 = 0
  t2 = 1

  print(f'{"q":>20} {"r1":>20} {"r2":>20} {"r":>20} {"t1":>20} {"t2":>20} {"t":>20}')
  print(" ")

  while r2 != 0:
    q = r1 // r2
    r = r1 - q * r2
    t = t1 - q * t2

    print(f'{"%20.0d" % q} {"%20.0d" % r1} {"%20.0d" % r2} {"%20.0d" % r} {"%20.0d" % t1} {"%20.0d" % t2} {"%20.0d" % t}')

    r1 = r2
    r2 = r
    t1 = t2
    t2 = t
  
  print(f'{"-":>20} {"%20.0d" % r1} {"%20.0d" % r2} {"-":>20} {"%20.0d" % t1} {"%20.0d" % t2} {"-":>20}')

  print(f'GCD({a}, {b}) = {r1}')

  if r1 == 1:
    if t1 > 0:
      print(f'Multiplicative inverse of {b} in Z{a} = {t1}')
    else:
      print(f'Multiplicative inverse of {b} in Z{a} = {t1} or {a + t1}')
  else:
    print('Multiplicative inverse does not exist')





def main():

  a = int(input('Enter a: '))
  b = int(input('Enter b: '))
  multInv(a,b)


   

main()    
