def calcMultInv(a: int, b: int):
  r1 = a
  r2 = b
  t1 = 0
  t2 = 1
 
  while r2 != 0:
    q = r1 // r2
    r = r1 - q * r2
    t = t1 - q * t2
    print(f'{"%20.0d" % q} {"%20.0d" % r1} {"%20.0d" % r2} {"%20.0d" % r} {"%20.0d" % t1} {"%20.0d" % t2} {"%20.0d" % t}')
    r1 = r2
    r2 = r
    t1 = t2
    t2 = t
 
  if r1 == 1:
    if t1 > 0:
      return t1
    else:
      return a + t1
  else:
    return None
 
# Function to calculate GCD
def GCD(a, b):
     
    if (a == 0):
        return b
         
    return GCD(b % a, a)
 
# Function to calculate LCM
def LCM(a, b):
     
    return (a * b) // GCD(a, b)
 
# Function to check if aelements
# in the array are pairwise coprime
def checkPairwiseCoPrime(A, n):
     
    # Initialize variables
    prod = 1
    lcm = 1
 
    # Iterate over the array
    for i in range(n):
 
        # Calculate product of
        # array elements
        prod *= A[i]
 
        # Calculate LCM of
        # array elements
        lcm = LCM(A[i], lcm)
 
    # If the product of array elements
    # is equal to LCM of the array
    if (prod == lcm):
        return 1
    else:
        return 0

def main():
  n = int(input('Enter no. of equations: '))
  a = list(map(int, input('Enter a0 a1 a2 ... an: ').split()))
  m = list(map(int, input('Enter m0 m1 m2 ... mn: ').split()))

  if checkPairwiseCoPrime(m,len(m)) != 1 :
    print("Modulo are not co prime so answer does not exist")
    return

  pM = 1
  for i in range(n):
    pM *= m[i]
   
  M = []
  for i in range(n):
    M.append(pM // m[i])
 
  MInv = []
  for i in range(n):      
    MInv.append(calcMultInv(m[i], M[i]))
 
  x = 0
  for i in range(n):
    x = (x + a[i] * M[i] * MInv[i]) % pM
 
  print('\na =', a)
  print('m =', m)
  print('pM =', pM)
  print('M =', M)
  print('MInv =', MInv)
  print('\nx =', x)
 
main()
