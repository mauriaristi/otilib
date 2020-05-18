def iterativeMCX(nvar,order):
    
    
    nevals = comb(nvar+order-1,nvar-1,exact=True)
    nderiv = comb(nvar+order,nvar,exact=True)
    derivs = np.zeros(nderiv)
    direction_referral = 0
    
    for i_eval in range(nevals):
        
        # look for the direction:
        
        while 1:
            
            suma = 0
            direction_referral += 1
            
            for i in np.base_repr(direction_referral,order+1):
                
                suma += int(i)
                
            # end for 
            
            if suma == order:
                
                break
                
            # end if
            
        # end while
        
        
        
        print("\n Direction in base representation: ",np.base_repr(direction_referral,order+1))
        
        
        # create the list of numbers with the equivalence of directions
        
        equivalence = np.zeros(nvar,dtype = int)
        i = 0
        
        count = 0
        
        element = np.base_repr(direction_referral,order+1)
        element = element[::-1] # reverse the string

        for num in element:
            
            equivalence[i] = (2**(int(num))-1)<<count
            
            print("Binary equivalence of direction ",i,": ",bin(equivalence[i]))
            
            count += int(num)
            i += 1

        # end for
        
        coefs = np.empty(2**(order))
        
        for i in range(2**(order)):

            var = 0
            coef = 0

            for equiv in equivalence:
                
                deriv_order = bin(equiv & i).count("1")
                
                coef += ((order + 1)**var)*deriv_order
                var += 1
            
            # end for

            
            count = 0

            for k in range(coef):

                order_k = 0

                for number in np.base_repr(k,order+1):

                    order_k+= int(number)

                if order_k <= order:

                    count+=1

            # end for
                    
            derivs[count] = count+1

        # end for

    # end for
    print(derivs)

