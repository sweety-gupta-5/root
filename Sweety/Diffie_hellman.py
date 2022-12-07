# Enter the approved prime number and the primitive root g.
Prime_no = int(input("Enter Prime No. q: "))
g = int(input("Enter Primitive root (a<q) : "))
# Enter  private key chosen by A and B
PkXa = int(input("Enter Private key of A (xa<q) : "))
PkXb = int(input("Enter Private key of B (xb<q) : "))
# Calculate public key of A and B
ya = g**PkXa % Prime_no
yb = g**PkXb % Prime_no
# Calculate shared session key K
ka = yb**PkXa % Prime_no
kb = ya**PkXb % Prime_no
print("A’s Public Key Ya =",ya)
print("B’s Public Key Yb =",yb)
print("Shared session key k =",ka)