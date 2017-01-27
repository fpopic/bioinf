# Student assignment project (Bioinformatics)
**A representation of a compressed de Bruijn graph for pan-genome analysis that enables search**

Goal: Implementation of A1 & A2 algorithms and comparison to the original implementation 

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

```
$ ls usr/local/include/
divsufsort64.h  divsufsort.h  sais.h  sais.hxx  sdsl

$ ls /usr/local/lib/
libdivsufsort64.a  libsais.a  libdivsufsort.a  libsdsl.a  pkgconfig
```

# Compiling 

```
cd REPO_FOLDER/bioinf
cmake --build cmake-build-debug --target debruijn.exe -- -j 4
cmake --build cmake-build-debug --target debruijn_tests.exe -- -j 4
```

# Running
```
cd REPO_FOLDER/bioinf
./debruijn.exe test/res/input/XXX.fasta test/res/input/XXX.k <A1 or A2> test/res/output/XXX.
```
# Running tests
```
cd REPO_FOLDER/bioinf/test
```
All tests
```
./debruijn_tests.exe
```
A1 tests
```
./debruijn_tests.exe --gtest_filter=a1*
```
A2 tests
```
./debruijn_tests.exe --gtest_filter=a2*
```
