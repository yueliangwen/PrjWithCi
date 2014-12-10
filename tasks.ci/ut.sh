#!/bin/sh
mkdir $WORKSPACE/ci/ut_result
#$WORKSPACE/build/ut/ut_gtest --gtest_output=xml:$WORKSPACE/ci/ut_result/gtest.xml
cd $WORKSPACE/build/ut/
./ut_gtest --gtest_output=xml:$WORKSPACE/ci/ut_result/gtest.xml
