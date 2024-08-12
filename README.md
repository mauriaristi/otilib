# Instructions to build the OTIlib/pyoti website:



0. you will need to clone two branches of the repository in the same directiory, i.e

	- ```folder/otilib-master``` Contains the master branch.
	- ```folder/otilib-gh-pages``` Contains the gh-pages branch (this!).




1. Move into ```otilib-master/doc``` directory.

``` bash
cd  path/to/otilib-master/doc
```

2. Install the required libreries. For this, use ```pip``` to install the list of elements from 

``` bash
pip  install -r requirements.txt
```

In MacOS, pandoc will be needed. Use ```brew``` to install this dependency

``` bash
brew  install pandoc
```

3. Copy the files in ```otilib-master/examples/notebooks/\*.ipynb``` into ```otilib-master/doc/source/notebooks/```:

``` bash
make html
```	


4. run the make command to run the sphinx documentation generator. This will update the folder ```otilib-gh-pages/html``` with the compiled library.

``` bash
make html
```

5. Move into ```otilib-gh-pages``` directory.

``` bash
cd  path/to/otilib-gh-pages
```

6. Remove the previous website information. Keep this file (README.md), the html folder and the Makefile file in the ```otilib-gh-pages/``` directory

``` bash
rm -rf -v !(html|Makefile|README.md)
```

6. Move all the contents of the otilib-gh-pages/html folder into the otilib-gh-pages/ folder  

``` bash
mv html/* .
```

7. Add and commit the changes to the gh-pages branch, and push to the repository.