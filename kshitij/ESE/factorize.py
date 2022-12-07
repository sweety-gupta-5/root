import math  
def prime_factors(num):  
    flag=0
    while num % 2 == 0:  
        flag=1
        num = num / 2         
    if flag==1:
         print('factorize by prime no.:',2)      
 
    for i in range(3, int(math.sqrt(num)) + 1, 2):  
        # while i divides n , print i ad divide n  
        print(i)
        while num % i == 0:  
            print('factorize by prime no.:',i)  
            num = num / i  
    if num > 2:  
        print('factorize by prime no.:',num)  
 
# calling function  
def main():
  num = int(input('Enter number: '))
  prime_factors(num)
 
main()