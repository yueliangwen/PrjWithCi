一、项目目录架构
==
- 目录如下：

`3rd` 存放第三方源代码项目（gtest）

`build` 项目使用外部构建，整个项目的构建目录

`ci` 项目产生的CI服务器需要的数据

`include` 存放接口文件（se-interface）或binary库的头文件

`lib` binary库

`src` 项目的源代码目录

`ut` 项目的单元测试目录

`st` 项目的系统测试目录

`script` 项目的脚本目录

`rpm` 项目发布

`doc` 项目文档

二、CMake相关
==
- 因为赖，不想些更多的Makefile
- 从写Makefile改成写CMakeLists.txt
- 看一段CMakeLists.txt吧。

三、GCOV相关
==
- GCOV 是 GCC Coverage
- 是一个测试代码覆盖率的工具
- 也是一个命令行方式的控制台程序
- 添加上`-fprofile-arcs -ftest-coverage`编译选项就能启用
- 编译后生成\*.gcno文件，执行该代码片段生成\*.gcna
- 然后执行gcov就能生成\*.gcov覆盖率报告

四、GTEST相关
==
- **GTest**是google出品的[单元测试](http://zh.wikipedia.org/wiki/单元测试)框架!
- [UT](http://en.wikipedia.org/wiki/Unit_testing)具有以下几个基本概念：

`断言` ->`测试` ->`测试用例` ->`测试套件（整个单元测试）`
- `断言`gtest提供以下断言宏（检查宏）：
```cpp
//在gtest中断言是一系列 EXPECT_* 和 ASSERT_* 的检查宏。
EXPECT_*(); // 失败时，案例继续往下执行。
ASSERT_*(); // 失败时，直接在当前函数中返回。
```
- `测试`测试由一系列断言来检查功能代码。
- `测试用例`根据功能代码将一系列测试组织起来，这就形成了测试用例。
- `测试套件`共享某个固件环境的所有测试合称为一个“测试套件”。    
```cpp
// 以下代码对应了断言、测试、测试用例等几个概念
#include "gtest/gtest.h"

int returnOne() {
    return 1;
}

int returnTwo() {
    return 2;
}

TEST(test_case_name, test_name) {
    //... test body ...
    ASSERT_EQ(1, returnOne());
    EXPECT_EQ(2, returnTwo());
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
- 执行演示

[**coding show!**](https://code.google.com/p/googletest/wiki/Samples)
- GMOCK

五、CI相关
==
- 名持续集成
- 为项目提供质量保证等配套功能
- 大体功能如下（不限于）

`代码静态检查` `单元测试` `系统测试` `代码覆盖率`

`日构建` `版本发布` `构建report`
- CI服务器使用及演示

六、总结&MORE
==
- 更多的工作量
- 避免新增代码对已有代码的影响
- 更好的工作交接
- ST框架需要集成
- 静态检查是否必要

七、使用
==
需要配合jenkins和git使用才能发挥PrjWithCi最佳实践。
- 执行`sh build.sh help`获取帮助
- 执行`sh build.sh ci`构建具有包含UT功能的CI
- 执行`sh build.sh release`构建发布版本
