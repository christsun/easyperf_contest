clang-17 ${1} -O3 -g -o build/${2}
if [ $? != "0" ]; then
    clang++-17 ${1} -O3 -g -o build/${2}
fi