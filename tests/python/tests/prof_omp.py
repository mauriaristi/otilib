
import timeit


setup = '''
import pyoti.sparse as oti
X = (oti.ones({0})+oti.e(1,order={1}))**30
'''

add_stmt = '''
Y = X+X
'''

mul_stmt = '''
Y = X*X
'''
print('Addition')
for N in [2,20,200,2000,20000,20000]:
	
    for ordi in [4,10]:

        num = 10000
        t = timeit.timeit(stmt=add_stmt,setup=setup.format(N,ordi), number=num)
        print("Case: N:{0:5d}, order:{1:2d}, time: {2:12.3f} us".format(N,ordi,t/num*1000000))
		

print('Multiplication')
for N in [2,20,200,2000,20000,20000]:
        
    for ordi in [4,10]:

        num = 10000
        t = timeit.timeit(stmt=mul_stmt,setup=setup.format(N,ordi), number=num)
        print("Case: N:{0:5d}, order:{1:2d}, time: {2:12.3f} us".format(N,ordi,t/num*1000000))
    # end for
# end for
