cmake_minimum_required(VERSION 3.21)
project(assign C)

set(CMAKE_C_STANDARD 11)

#add_executable(
#        text/sushe.c
#        text/xueshengchengji.c)

#add_executable(sushe.c)
#add_executable(assign2 assign2.c)
#add_executable(xueshengchengji xueshengchengji.c)
add_executable(cainiao assign/cainiao.c assign/assign.h assign/function.c)
#add_executable(xuecsheng1 text/xuecsheng1.c)
#add_executable(assign2 text/assign2.c)
#add_executable(suiban text/suiban.c)
#add_executable(sushe text/sushe.c)
add_executable(课程设计 text/课程设计.c)