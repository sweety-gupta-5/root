from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad

# EAX Mode

plaintext = b'Hello World'
print("PlainText :",plaintext)
print("")

print("EAX MODE")
key = get_random_bytes(16)
cipher = AES.new(key, AES.MODE_EAX)
ciphertext, tag = cipher.encrypt_and_digest(plaintext)
print("CipherText :",ciphertext)
nonce = cipher.nonce
cipher = AES.new(key, AES.MODE_EAX, nonce)
plaintext = cipher.decrypt_and_verify(ciphertext, tag)
print("PlainText :",plaintext)
print("")

# CFB Mode
print("CFB MODE")
cipher = AES.new(key, AES.MODE_CFB)
ciphertext = cipher.encrypt(plaintext)
print("CipherText :",ciphertext)
iv = cipher.iv

decrypt_cipher = AES.new(key, AES.MODE_CFB, iv=iv)
plaintext = decrypt_cipher.decrypt(ciphertext)
print("PlainText :",plaintext)
print("")


# CBC Mode
print("CBC MODE")
cipher = AES.new(key, AES.MODE_CBC)
ciphertext = cipher.encrypt(pad(plaintext, AES.block_size))
print("CipherText :",ciphertext)
iv = cipher.iv

decrypt_cipher = AES.new(key, AES.MODE_CBC, iv)
plaintext = decrypt_cipher.decrypt(ciphertext)
print("PlainText :",plaintext)
print("")


# OFB Mode
print("OFB MODE")
cipher = AES.new(key, AES.MODE_OFB)
ciphertext = cipher.encrypt(plaintext)
print("CipherText :",ciphertext)
iv = cipher.iv

decrypt_cipher = AES.new(key, AES.MODE_OFB, iv=iv)
plaintext = decrypt_cipher.decrypt(ciphertext)
print("PlainText :",plaintext)
print("")

# CTR MODE
print("CTR MODE")
cipher = AES.new(key, AES.MODE_CTR)
ciphertext = cipher.encrypt(plaintext)
print("CipherText :",ciphertext)
nonce = cipher.nonce

decrypt_cipher = AES.new(key, AES.MODE_CTR, nonce=nonce)
plaintext = decrypt_cipher.decrypt(ciphertext)
print("PlainText :",plaintext)
print("")