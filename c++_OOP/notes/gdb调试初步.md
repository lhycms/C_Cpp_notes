<font color="orange" size="4"><b>想使用`gdb`的时候，需要在`g++`加上`-g`选项</b></font>

`g++ -Wall -Werror -g test.cpp -o test`

# 1. `gdb` 命令
1. `gdb`: 进入 gdb 环境
2. `file`: 加载可执行文件
3. `run`: 一次性运行完可执行文件
4. `start`: 开始运行可执行文件，一次一行
5. `list`: 列出将要执行的代码
6. `next`: 单步调试 -- 如果下一步是函数调用语句，则直接越过这个函数 (gdb在背地里悄悄把函数执行完)
7. `step`: 单步调试 -- 如果下一步是函数调用语句，则进入到这个函数中
    - `info args`: 查看函数的参数情况
8. `continue`: 继续执行程序，直至下一个断点前
9. `print <variable_name>`: 在执行过程中，查看变量的值
    - `set <varibale>=<value/variable>`: 设置/改变 变量的值
10. `br <function_name/row_of_code>`: 在 某个函数/代码的某行 处打断点（breakpoint）
    - `info breakpoints`: 查看所有的断点信息 (information of all breakpoints)
    - `delete <breakpoint_num>`: 删除断点，`<breakpoint_num>` 通过 `info breakpoints` 查看
11. `gdb -tui -q p2psrv`: 可视化debug
12. `finish`: 结束这个 program
13. `quit`: 退出 gdb