#!/bin/sh
mkdir $WORKSPACE/ci/cov_result
#cd $WORKSPACE/build/src/CMakeFiles/dir_srcs.dir
cd $WORKSPACE
gcovr --exclude=^3rd/* --exclude=^deps/* --exclude=^src/example/* -x -r . > $WORKSPACE/ci/cov_result/coverage.xml
