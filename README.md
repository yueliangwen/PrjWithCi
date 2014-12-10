一、项目构建第一步
	如果只是编译生成该项目的Release版本的话，在build目录执行如下命令:
	>> cmake ..
	如果只是编译生成该项目的Debug版本的话，在build目录执行如下命令:
	>> cmake -DCMAKE_BUILD_TYPE=Debug ..
	如果要生成该项目的UT或代码覆盖数据需要在build目录执行如下命令:
	>> cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_GCOV=1 ..


二、项目构建第二步
	接下来可以直接在build目录执行make编译项目了，
	如果要了解更多的编译目标可以执行make help获得帮助。

三、配合jenkins和git能提供C++开发测试到发布的完整解决方案。
