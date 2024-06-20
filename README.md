# Instructions to build the OTIlib/pyoti website:


1. you will need to clone two branches of the repository in the same directiory, i.e

	- ```folder/otilib-master``` Contains the master branch.
	- ```folder/otilib-gh-pages``` Contains the gh-pages branch (this!).

2. Copy the files in otilib-master/examples/notebooks/\*.ipynb into otilib-master/doc/source/notebooks/:
	
3. Move into otilib-master/doc directory.

4. run the make command to run the sphinx documentation generator. This will update the folder ```otilib-gh-pages/html``` with the compiled library.

``` bash
make html
```

5. Move into ```otilib-gh-pages``` directory.

6. remove the previous website information. Keep this file (README.md), the html folder and the Makefile file in the ```otilib-gh-pages/``` directory

``` bash
rm -rf -v !(html|Makefile|README.md)
```


6. Move all the contents of the otilib-gh-pages/html folder into the otilib-gh-pages/ folder  

``` bash
mv html/* .
```