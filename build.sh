#!/bin/sh

BUILD_PATH="./build"

function Log
{
    echo "[BUILD] " `date +"%Y-%m-%d %H:%M:%S"` "    " $1;
}

function CreateBuildDirectory
{
    Log "checking build path..."
    if [ ! -x "${BUILD_PATH}" ]; then
        Log "creating build path..."
        mkdir "${BUILD_PATH}"
        ##由于权限可能导致创建失败，将在使用该目录时候检查
    fi
}

function PrintUsage
{
    echo "Usage:"
    echo "  $0 {release|debug|ci|clean}"
    echo "  - realse cmake .."
    echo "  - debug  cmake -DCMAKE_BUILD_TYPE=Debug .."
    echo "  - ci    cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_GCOV=1 .."
    echo "  - clean  clean .."
}

function BuildTarget
{
    Log "access ${BUILD_PATH}"
    cd ${BUILD_PATH}
    if [ $? -eq 0 ]; then
        Log "execute cmake $1"
        cmake $1
        if [ $? -eq 0 ]; then
            make
        else
            Log "execute cmake $1 failed!"
        fi
    else
        Log "access ${BUILD_PATH} failed!"
    fi
}

function Build
{
    case "x$1" in
        xrelease)
            CreateBuildDirectory
            BuildTarget ".."
            ;;
        xdebug)
            CreateBuildDirectory
            BuildTarget "-DCMAKE_BUILD_TYPE=Debug .."
            ;;
        xci)
            CreateBuildDirectory;
            BuildTarget "-DCMAKE_BUILD_TYPE=Debug -DENABLE_GCOV=1 .."
            ;;
        xclean)
            Log "cleaning..."

            if [ -x "${BUILD_PATH}" ]; then
                rm -rf "${BUILD_PATH}";
            fi
            ;;
        *)
            PrintUsage;
            ;;
    esac
}

#执行入口
Build $1
