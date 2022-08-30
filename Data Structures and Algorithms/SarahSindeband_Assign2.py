# COP 3410- Assignment 2
# Sarah Sindeband
# 2/7/22
# Fixing the classes from the lecture, adding new methods and demonstrating the functionality of all methods

class CreditCard:
    '''A consumer credit card.'''


    def __init__ (self, customer = "Name", bank = "Bank", acnt = "5391 0375 9387 5309", limit = 1000, balance = 0):
        # default constructor setting balance to zero so the balance parameter is optional
        # set other variables to values to create template user, then allow user to fill in their information
        '''Create a new credit card instance.
        The initial balance is zero.
        customer: the name of the customer (e.g., John Bowman )
        bank: the name of the bank (e.g., California Savings )
        acnt : the acount identifier (e.g., 5391 0375 9387 5309 )
        limit: credit limit (measured in dollars)
        '''
        self._customer = customer 
        self._bank = bank
        self._account = acnt
        self._limit = limit
        self._balance = balance
        purchase = 0
        
    def get_customer(self):   
        '''Return name of the customer.'''
        return self._customer
    
    def get_bank(self):
        '''Return the bank s name.'''
        return self._bank
    
    def get_account(self):
        '''Return the card identifying number (typically stored as a string).'''
        return self._account
    
    def get_limit(self):
        '''Return current credit limit.'''
        return self._limit
    
    def get_balance(self):
        '''Return current balance.'''
        return self._balance
    
    def set_balance(self, balance):
        """Updating the balance when the optional parameter is used."""
        self._balance = balance
        self._limit -= balance
        
    def make_purchase(self, purchase):
        """Updating the balance and limit when a purchase is made."""
        if (purchase + self._balance) <= self._limit:
            self._balance += purchase
            self._limit -= purchase
        elif (purchase + self._balance) > self._limit:
            # if the purchase is greater than the available balance, the balance and limit will not be updated
            print(self._bank, "card declined")
            
        
    def make_payment(self, payment):
        """Updating the balance and limit when a payment is made."""
        if (self._balance - payment) >=0:
            self._balance -= payment
            # Also need to update the limit to reflect the new balance
            self._limit += payment
        elif (self._balance - payment) < 0:
            # if the purchase is greater than the available balance, the balance and limit will not be updated
            print("Make a payment between $ 1 and", self._balance)
            
        
class ModernCreditCard(CreditCard):
    def __init__ (self, customer = "Name", bank = "Name", acnt = "5391 0375 9387 5309", limit = 1000, balance = 0, apr = 0.0825):
     '''Create a new predatory credit card instance.
     The initial balance is zero.
     customer the name of the customer (e.g., John Bowman )
     bank the name of the bank (e.g., California Savings )
     acnt the acount identifier (e.g., 5391 0375 9387 5309 )
     limit credit limit (measured in dollars)
     apr annual percentage rate (e.g., 0.0825 for 8.25% APR)
     '''
     
     super(). __init__ (customer, bank, acnt, limit, balance) # call super constructor
     self._apr = apr
     def make_purchase(self, purchase):                   #may not be fully operation yet
         '''Charge given price to the card, assuming sufficient credit limit.
            Return True if charge was processed.
            Return False and assess 5 fee if charge is denied.
         '''
         if (purchase + self._balance) <= self._limit:
             self._balance += purchase
             self._limit -= purchase
             return True
         elif (purchase + self._balance) > self._limit:
             self._balance += purchase
             self._limit -= purchase
             print("$ 5 fee for an unsuccessful payment.")
             return False
         success = super().make_purchase(purchase)     #inherited method
         if not success:
             self._balance += 5
             # Also update the limit to reflect the new balance
             self._limit -= 5
         return success
         
    def process_month(self):
        '''Assess monthly interest on outstanding balance'''
        if self._balance > 0:
            #if positive balance, convert APR to monthly multiplicative factor
            monthly_factor = self._balance * self._apr
            self._balance += monthly_factor
            # Also update the limit to reflect the new balance
            self._limit -= monthly_factor
            
      
class Vector:
    """Represent a vector in a multidimensional space."""
    def __init__(self, d):
        """Create d-dimensional vector of zeros."""
        self._coords = [0] * d
    def __len__(self):
        """Return the dimension of the vector."""
        return len(self._coords)
    def __getitem__(self, j):
        """Return the jth coordinate of vector."""
        return self._coords[j]
    def __setitem__(self, j, val):
        """Set jth coordinate of vector to given value."""
        self._coords[j] = val
    def __add__(self, other):
        """Return the sum of two vectors."""
        if len(self) != len(other):
            raise ValueError('Dimensions must agree.')
        result = Vector(len(self))
        for j in range (len(self)):
            result[j] = self[j] + other[j]
        return result
    def __eq__(self, other):
        """Return True if vector has same coordinates as other."""
        return self._coords == other._coords
    def __ne__(self, other):
        """Return True if vector differs from other."""
        return not self == other
    def __str__(self):
        """Produce string representation of vector."""
        return '<' + str(self._coords)[1:-1]+'>'
    # 2.9
    def __sub__(self, other):                   # self is left, other is right
        """Return the difference between two vectors"""
        if len(self) != len(other):
            raise ValueError('Dimensions must agree.')
        difference = Vector(len(self))
        for j in range (len(self)):
            difference[j] = self[j] - other[j]
        return difference
    # 2.10
    def __neg__(self):
        """Make all of the elements negative and return them"""
        neg = Vector(len(self))
        for i in range (len(self)):
            neg[i] = self[i] * -1
        return neg
    # 2.12 & 2.14
    """Return the multiples of the coordinates of the vector or the sum of the product of two vectors"""
    def __mul__(self, other):
        if isinstance(other, (Vector)):
            if len(self) != len(other):
                raise ValueError('Dimensions must agree.')
            else:
                v_prod = 0
                for n in range(len(self)):
                    v_prod += self[n] * other[n]
                return v_prod
        else:
            prod = Vector(len(self))
            for k in range (len(self)):
                prod[k] = self[k] * other
            return prod

    # 2.13
    """Return the multiples of the coordinates of the vector"""
    def __rmul__(self, other):
        prod = Vector(len(self))
        for k in range (len(self)):
            prod[k] = self[k] * other
        return prod



if __name__ == "__main__":
    wallet = []
    visa = ModernCreditCard('Sally Shoo', 'Vells','1234 5678 9012 3456', 5000,0.0825)
    cc = CreditCard( 'Sally Shoo', '1st Bank' , '5391 0375 9387 5309' , 1000)
    wallet.append(visa)
    wallet.append(cc)
    

    
    # 2.7
    print("\n2.7")
    print('cc account:', cc.get_account())
    print('cc limit:', cc.get_limit())
    print('cc balance:', cc.get_balance())
    
    cc2 = CreditCard( 'Sally Shoo', '2nd Bank' , '5391 0375 9387 5309' , 7000, 200)
    print('cc2 account:', cc2.get_account())
    print('cc2 limit:', cc2.get_limit())
    print('cc2 balance:', cc2.get_balance())

    # 2.8
    print("\n2.8")
    new_wallet = []    
    card1 = ModernCreditCard('Sally Shoo', 'Vells','1234 5678 9012 3456', 5000,0.0825)   #calling the constructor
    card2 = ModernCreditCard('Sally Shoo', 'Citi Bank', '3485 0399 3395 1954' , 3500, 0.0825)
    card3 = ModernCreditCard('Sally Shoo', 'Capital One', '5391 0375 9387 5309 , 2500' , 2500, 0.0825)
    new_wallet.append(card1)
    new_wallet.append(card2)
    new_wallet.append(card3)

    for val in range(1,30):
        card1 = new_wallet[0].make_purchase(val)
        card2 = new_wallet[1].make_purchase(val*2)
        card3 = new_wallet[2].make_purchase(val*3)

    # 2.9
    u = Vector(3)
    u[0] = 2
    u[1] = 4
    u[2] = 6
    v = Vector(3)
    v[0] = 1
    v[1] = 3
    v[2] = 5
    ans = u - v
    print("\n2.9: \nu:", u,"\nv:",v, "\nu - v = ", ans)

    # 2.10
    ans2 = -v
    print("\n2.10: \nv = ",v, "\n-v = ", ans2)


    # 2.11
    print("""
    2.11:
    The Vector class definition can be revised by adding a radd function that
    would take the other syntax featuring the "self" on the right side rather
    than the left side.
    """)

    # 2.12
    ans3 = v * 3
    print("\n2.12: \nv = ",v, "\nv * 3 =", ans3)

    # 2.13
    ans4 = 3 * v
    print("\n2.13: \n3 * v =", ans4)

    # 2.14
    ans5 = u * v
    print("\n2.14: \nu:", u,"\nv:",v, "\nu * v = ", ans5)

    # Test cases
    print("\n\nTesting CreditCard")
    # Creating a new instance of class CreditCard & getting account information from the user
    cc1 = CreditCard()
    cc1._bank = input("\nPlease enter the name of the bank: ")
    cc1._customer = input("Please enter the account holder's name: ")
    cc1._account = input("Please enter the account number: ")
    print("Your current balance is $", cc1.get_balance())
    ques = input("Is this correct? (Y for yes, N for no): ")
    if ques == 'Y':
        print("Thank you for confirming your balance.")
    elif ques == 'N':
        cc1._balance = int(input("Please enter the correct balance: "))
        cc1._limit -= cc1._balance
    print("Your limit is $", cc1.get_limit())
    # Using the make purchase method to update the balance and the limit
    ques2 = input("Do you want to add a charge to the card? (Y for yes, N for no): ")
    if ques2 == 'Y':
        cc1.make_purchase(int(input("Enter the amount: ")))
        print("Your new balance is: $", cc1.get_balance())
        print("You have $", cc1.get_limit(), "in available credit.")
    # Using the make payment function to update the balance and the limit
    ques3 = input("Would you like to make a payment? Y for yes, N for no): ")
    if ques3 == 'Y':
        cc1.make_payment(int(input("Enter the payment amount: ")))
        print("Your new balance is: $", cc1.get_balance())
        print("You have $", cc1.get_limit(), "in available credit.")
    print("\nStatement Details:")
    print("\nBank:", cc1.get_bank())
    print("Account Holder:", cc1.get_customer())
    print("Account #:", cc1.get_account())
    print("Balance:", cc1.get_balance())
    print("Available Credit:", cc1.get_limit())
        
    print("\n\nTesting ModernCreditCard")
    # Creating a new instance of class ModernCreditCard & getting account information from the user
    cc2 = ModernCreditCard()
    cc2._bank = input("\nPlease enter the name of the bank: ")
    cc2._customer = input("Please enter the account holder's name: ")
    cc2._account = input("Please enter the account number: ")
    print("Your current balance is $", cc2.get_balance())
    _ques = input("Is this correct? (Y for yes, N for no): ")
    if _ques == 'Y':
        print("Thank you for confirming your balance.")
    elif _ques == 'N':
        cc2._balance = int(input("Please enter the correct balance: "))
        cc2._limit -= cc2._balance
    print("Your limit is $", cc2.get_limit())
    # Using the make purchase method to update the balance and the limit
    _ques2 = input("Do you want to add a charge to the card? (Y for yes, N for no): ")
    if _ques2 == 'Y':
        cc2.make_purchase(int(input("Enter the amount: ")))
        print("Your new balance is: $", cc2.get_balance())
        print("You have $", cc2.get_limit(), "in available credit.")
    # Using the make payment function to update the balance and the limit
    _ques3 = input("Would you like to make a payment? Y for yes, N for no): ")
    if _ques3 == 'Y':
        cc2.make_payment(int(input("Enter the payment amount: ")))
        print("Your new balance is: $", cc2.get_balance())
        print("You have $", cc2.get_limit(), "in available credit.")

    # Using process month function in the monthly statement   
    cc2.process_month()
    print("\nStatement Details:")
    print("\nBank:", cc2.get_bank())
    print("Account Holder:", cc2.get_customer())
    print("Account #:", cc2.get_account())
    print("Balance with APR:", cc2.get_balance())
    print("Available Credit:", cc2.get_limit())

    # Testing the Vector Class
    print("\n\nTesting the Vector Class")
    # Creating a new instance of the Vector class
    vec = Vector(3)
    vec[0] = 10
    vec[1] = 20
    vec[2] = 30
    print("\nVector 1 =", vec)

    vec2 = vec + [1, 1, 1]
    print("Adding 1 to all items in Vector 1 to create Vector 2:", vec2)

    res = vec == vec2
    print("True or false, Vector 1 is equal to Vector 2?\n", res)

    res2 = vec != vec2
    print("True or false, Vector 1 is NOT equal to Vector 2?\n", res2)

    str_vec = vec.__str__()
    print("Making the Vector into a string:", str_vec)

    sub_vec = vec2 - vec
    print("Vector 2 minus Vector 1 =", sub_vec)

    neg_vec = -vec
    print("Making Vector 1 negative:", neg_vec)

    mul_vec = vec * 2
    print("Multiplying Vector 1 times 3 =", mul_vec)

    r_mul_vec = 3 * vec
    print("Multiplying 3 times Vector 1 =", r_mul_vec)
    
    
    























    
