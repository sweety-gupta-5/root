# -*- coding: utf-8 -*-
"""
Created on Sun Dec  4 16:18:54 2022

@author: SWEETY
"""

import hashlib
  
# prints all available algorithms
print ("The available algorithms are : ", end ="")
print (hashlib.algorithms_guaranteed)


  
# initializing string
str = "GeeksforGeeks"
  
# encoding GeeksforGeeks using encode()
# then sending to SHA512()
result = hashlib.sha512(str.encode())
  
# printing the equivalent hexadecimal value.
print("The hexadecimal equivalent of SHA512 is : ")
print(result.hexdigest())
