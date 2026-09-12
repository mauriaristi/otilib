# Generating the documentation.

This file contains the instructions to generate the documentation for the [otilib](https://github.com/mauriaristi/otilib/) library.

# 1. Requirements

First, make sure you have a compiled version of the library as a portion of the documentation is generated from the actual python binary files. You will need to install the envirnoment from the environment.yml file in the root folder of the repository.

## 1.1 Folder structure

You need two folders: one that contains the master branch of the repository, and another one that contains the ```gh-pages``` branch.
```text
<root_folder>/
├── otilib-gh-pages/
├── otilib-master/
```
The name of the ```gh-pages``` folder is important

### Checkout the gh-pages branch of the repository on a separate folder.

Download the ```gh-pages``` branch of the repository on a folder that lives in the same root folder as the master branch. For this, while you are in a 

```bash
git clone -b gh-pages https://github.com/mauriaristi/otilib otilib-gh-pages
```


## 1.2 Dependencies

The additional requirements to generate the library are included in otilib-master/doc/requirements.txt. Install using ```pip```, as follows

``` bash
pip install -r requirements.txt
```

The following system tools are also required and are **not** installable via ```pip```; install them
into the ```pyoti``` conda environment directly:

``` bash
conda install -n pyoti -c conda-forge pandoc doxygen --solver rattler
```

```pandoc``` is required by ```nbsphinx``` to render the tutorial notebooks. ```doxygen``` is
required by the ```breathe```/```exhale``` extensions to generate the C API reference from
```include/oti/```.

# 2. Copy Tutorial jupyter notebook files.

Copy the files in ```otilib-master/examples/notebooks/\*.ipynb``` into ```otilib-master/doc/source/notebooks/```:

# 3. Make the html docs

Move into the folder ```otilib-master/doc/``` and run the f following command:

``` bash
make html
```	
This command is setup to modify the html folder in the ```otilib-gh-pages``` folder we setup earlier.

# 4. Move and clean ```gh-pages``` directory.

Change directory to the ```otilib-gh-pages``` folder
``` bash
cd  <root_folder>/otilib-gh-pages
```

Remove the previous docstring information. Keep this ```README.md``` file, the ```html/``` folder and the ```Makefile``` file in the ```otilib-gh-pages/``` directory

``` bash
rm -rf -v !(html|Makefile|README.md)
```

Move all the contents of the ```otilib-gh-pages/html``` folder into the ``otilib-gh-pages/`` folder  

``` bash
mv html/* .
```

You can now add and commit the changes to the ```gh-pages``` branch, and push to the repository.
