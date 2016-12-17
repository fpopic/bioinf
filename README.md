# BioInf
Projekt iz predmeta Bioinformatika

## Dependencies (Project C++ libraries)
Installation will install files in folders:
headers =>  '/usr/local/include'
sources =>  '/usr/local/lib'

## Install sais-2.4.1
```sh
cd CLONED_REPOSITORY_FOLDER/lib/
unzip sais-2.4.1.zip
cd sais-2.4.1/
mkdir build
cmake -DCMAKE_BUILD_TYPE="Release" -DCMAKE_INSTALL_PREFIX="/usr/local"
sudo make
sudo make install
```

## Install sdsl-lite
```sh
cd CLONED_REPOSITORY_FOLDER/lib/
unzip sdsl-lite.zip
cd/sdsl-lite/
mkdir build
sudo ./install.sh /usr/local
```

Ignore:
	WARNING: .git/hooks directory does not exists. 
	The pre-commit hook is not installed.

## Folder structure after the installation went successful:
![Solid](http://www.deviantpics.com/images/2016/12/16/Selection_135.png)
