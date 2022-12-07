

#Iterative Function to calculate(x ^ n) % p in O(logy)
def power(x, y, p):
  res = 1 # Initialize result

  x = x % p # Update x if it is more than or equal to p

  while (y > 0):
#If y is odd, multiply x with result
    if (y & 1):
      res = (res * x) % p

#y must be even now
    y = y >> 1 # y = y/2
    x = (x * x) % p

  return res

def encrypt(plaintext, e, n):
  return power(plaintext, e, n)

def decrypt(ciphertext, d, n):
  return power(ciphertext, d, n)

def main():

  print('1. Encrypt')
  print('2. Decrypt')
  
  choice = int(input('Enter your choice: '))

  if choice == 1:
    
    text = input('Enter plaintext: ')
    print('Enter public key:')
    e = int(input('e = '))
    n = int(input('n = '))
    print('Ciphertext :')
    for i in range(0, len(text)):
        plaintext= ord(text[i])
        ciphertext = encrypt(plaintext, e, n)
        print(ciphertext,end="")
    

    

    
  else:
    ciphertext = int(input('Enter ciphertext: '))

    print('Enter private key:')
    d = int(input('d = '))
    n = int(input('n = '))

    plaintext = decrypt(ciphertext, d, n)
    print("Plaintext: ",plaintext)

main()
