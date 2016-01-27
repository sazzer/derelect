#!/bin/bash

set -e

TOP=`dirname $0`
OUTPUT=$TOP/target

rm -rf $OUTPUT
mkdir -p $OUTPUT
cd $OUTPUT
cmake ..
make
make test

echo Build Complete
