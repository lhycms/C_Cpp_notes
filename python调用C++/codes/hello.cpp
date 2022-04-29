/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-04-22 15:06:01
 * @LastEditors: sch
 * @LastEditTime: 2022-04-22 15:29:51
 */
char const* greet()
{
   return "hello, world";
}


#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello)
{
    using namespace boost::python;
    def("greet", greet);
}