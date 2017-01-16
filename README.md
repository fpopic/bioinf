# BioInf
**A representation of a compressed de Bruijn graph for pan-genome analysis that enables search**

Goal: Implementation of A1 & A2 algorithms and comparison to original implementation 

Original Paper: https://almob.biomedcentral.com/articles/10.1186/s13015-016-0083-7

Original Implementation: https://www.uni-ulm.de/in/theo/research/seqana.html

Course website: http://www.fer.unizg.hr/predmet/bio

## Dependencies (Project C++ libraries)
Installation will install files in folders:
```
cmake 	=>  '/usr'
headers =>  '/usr/local/include'
sources =>  '/usr/local/lib'
```

### Install cmake-3.7.1
```sh
cd REPO_FOLDER/install/
unzip cmake-3.7.1.zip
cd cmake-3.7.1
sudo ./bootstrap --prefix=/usr
make
sudo make install
```

### Install sais-2.4.1
```sh
cd REPO_FOLDER/install/
unzip sais-2.4.1.zip
cd sais-2.4.1/
mkdir build
cmake -DCMAKE_BUILD_TYPE="Release" -DCMAKE_INSTALL_PREFIX="/usr/local"
make
sudo make install
```

### Install sdsl-lite-2.0
```sh
cd REPO_FOLDER/install/
unzip sdsl-lite.zip
cd sdsl-lite/
sudo ./install.sh /usr/local
```

##### Ignore:
```
	WARNING: .git/hooks directory does not exists. 
	The pre-commit hook is not installed.
```

### Google Test 1.8.0

Compiles together with sources as cmake subproject (/test/lib/gtest-1.8.0). No actions needed.
#
### Folder structure after the installation went successful:

![Solid](http://www.deviantpics.com/images/2016/12/16/Selection_135.png)


