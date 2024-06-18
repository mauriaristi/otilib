f = open('templates/cwrapmtemplate.f90','r')
fstr = f.read()
f.close()

m_idx = [1,2,3]
n_idx = [1,2,3,4]

for i in m_idx:
	for j in n_idx:
		m = i
		n = j
		mXnY = 'm{0}n{1}'.format(m,n)
		file = fstr.format(mXnY = mXnY)
		#print(file)
		f = open('cwrap{0}.f90'.format(mXnY),'w')
		f.write(file)
		f.close()