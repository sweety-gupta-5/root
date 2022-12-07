def isPrime(n):
  if n < 2:
    return False
 
  if n != 2 and n % 2 == 0:
    return False
 
  for i in range(3, int(n ** 0.5) + 1, 2):
    if n % i == 0:
      return False
 
  return True

def power(x, y, p):
  res = 1 # Initialize result
 
  x = x % p # Update x if it is more than or equal to p
 
  while (y > 0):
    # If y is odd, multiply x with result
    if (y & 1):
      res = (res * x) % p
 
    # y must be even now
    y = y >> 1 # y = y/2
    x = (x * x) % p
 
  return res

def isPrimitive(alpha,q):
    st = set()
    for i in range(1,q+1):
      st.add(power(alpha,i,q))
    if len(st) == q-1:
      return 1
    else : 
      return 0


q = 0
alpha = 0

while True:
  q = int(input("Enter Prime No. q: "))
  if isPrime(q):
    break
  else:
    print('Given number is not prime')
while True:
  alpha = int(input("Enter Primitive root (a<q) : "))
  if isPrimitive(alpha,q):
    break
  else:
    print('Given number is not coprime to ',q)

# Enter  private key chosen by A and B
priA= int(input("Enter Private key of A (xa<q) : "))
priB = int(input("Enter Private key of B (xb<q) : "))
# Calculate public key of A and B
pubA = alpha**priA % q
pubB = alpha**priB % q
# Calculate shared session key K
ka = pubB**priA % q
kb = pubA**priB % q
print("A’s Public Key pubA =",pubA)
print("B’s Public Key pubB =",pubB)
print("Shared session key k =",ka)