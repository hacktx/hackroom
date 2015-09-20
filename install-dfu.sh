sudo apt-get install openssl
wget http://dfu-util.sourceforge.net/releases/dfu-util-0.8.tar.gz
tar -zxvf dfu-util-0.8.tar.gz dfu-util-0.8
cd dfu-util-0.8
./autogen.sh
./configure
make
sudo make install
