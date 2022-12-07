def isPrime(n):
  if n < 2:
    return False

  if n != 2 and n % 2 == 0:
    return False

  for i in range(3, int(n ** 0.5) + 1, 2):
    if n % i == 0:
      return False
  
  return True

def gcd(a, b):
  r1 = a
  r2 = b

  while r2 != 0:
    q = r1 // r2
    r = r1 - q * r2

    r1 = r2
    r2 = r
  
  return r1

def multiplicativeInverse(a, b):
  r1 = a
  r2 = b
  t1 = 0
  t2 = 1

  while r2 != 0:
    q = r1 // r2
    r = r1 - q * r2
    t = t1 - q * t2

    r1 = r2
    r2 = r
    t1 = t2
    t2 = t

  if t1 > 0:
    return t1
  else:
    return a + t1

def generateKeys():
  p = 0
  q = 0

  while True:
    p = int(input('Enter large prime p: '))

    if isPrime(p):
      break
    else:
      print('Given number is not prime')

  while True:
    q = int(input('Enter large prime q: '))

    if p == q:
      print('q can not be equal to p')
    elif isPrime(q):
      break
    else:
      print('Given number is not prime')
  
  n = p * q
  phi = (p - 1) * (q - 1)

  e = 0
  d = 0

  while True:
    e = int(input(f'Enter number e coprime to {phi}: '))

    if gcd(e, phi) == 1:
      d = multiplicativeInverse(phi, e)

      if e != d:
        break
      else:
        print('e == d not allowed; Try some other value for e')
    else:
      print('Given number not coprime')

  print(f'Public key: {{{e}, {n}}}')
  print(f'Private key: {{{d}, {n}}}')



generateKeys()