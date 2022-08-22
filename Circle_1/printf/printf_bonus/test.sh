#!/bin/bash

# git clone https://github.com/Tripouille/printfTester.git
# cd printfTester
# # make make b 
# make b
# cd ..

git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
make 
sh m
sh b
./tester
cd ..

git clone https://github.com/gavinfielder/pft.git
cd pft
make
./enable-test bonus
./disable-test "*star*"
./test 0 1236
mv results.txt ../results.txt
cd ..

rm -rf pft
rm -rf ft_printf_tester
# rm -rf printfTester
make fclean
