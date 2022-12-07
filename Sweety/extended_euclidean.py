def extEuclidean(a: int, b: int):
  r1 = a
  r2 = b
  s1 = 1
  s2 = 0
  t1 = 0
  t2 = 1

  print(f'{"q":>30} {"r1":>30} {"r2":>30} {"r":>30} {"s1":>30} {"s2":>30} {"s":>30} {"t1":>30} {"t2":>30} {"t":>30}')
  print(" ")
  while r2 != 0:
    q = r1 // r2
    r = r1 - q * r2
    s = s1 - q * s2
    t = t1 - q * t2

    print(f'{"%30.0d" % q} {"%30.0d" % r1} {"%30.0d" % r2} {"%30.0d" % r} {"%30.0d" % s1} {"%30.0d" % s2} {"%30.0d" % s} {"%30.0d" % t1} {"%30.0d" % t2} {"%30.0d" % t}')

    r1 = r2
    r2 = r
    s1 = s2
    s2 = s
    t1 = t2
    t2 = t
  
  print(f'{"-":>30} {"%30.0d" % r1} {"%30.0d" % r2} {"-":>30} {"%30.0d" % s1} {"%30.0d" % s2} {"-":>30} {"%30.0d" % t1} {"%30.0d" % t2} {"-":>30}')
  
  print(f'GCD({a}, {b}) = {r1}\ns = {s1}\nt = {t1}')
  


def main():

  a = int(input('Enter a: '))
  b = int(input('Enter b: '))
  extEuclidean(a,b)


   

main()    
