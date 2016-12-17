# BioInf
Projekt iz predmeta Bioinformatika

## Dependencies (Project C++ libraries)
Installation will install files in folders:
headers =>  '/usr/local/include'
sources =>  '/usr/local/lib'

## Install sais-2.4.1
```sh
cd CLONED_REPOSITORY_FOLDER/lib/sais-2.4.1/
mkdir build
cmake -DCMAKE_BUILD_TYPE="Release" -DCMAKE_INSTALL_PREFIX="/usr/local"
sudo make
sudo make install
```

## Install sdsl-lite
```sh
cd CLONED_REPOSITORY_FOLDER/lib/sdsl-lite/
sudo ./install.sh /usr/local
```

## Folder structure after installation went successful:
![Solid](http://www.deviantpics.com/images/2016/12/16/Selection_135.png)
