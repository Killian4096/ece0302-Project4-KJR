# CMake generated Testfile for 
# Source directory: /home/killian/ece0302-KR/ece0302-Project4-KJR
# Build directory: /home/killian/ece0302-KR/ece0302-Project4-KJR
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(student-tests "student-tests")
set_tests_properties(student-tests PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;36;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
add_test(test00 "pathfinder" "/home/killian/ece0302-KR/ece0302-Project4-KJR/tests/maze00.png" "output00.png")
set_tests_properties(test00 PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;37;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
add_test(test00-compare "compare" "/home/killian/ece0302-KR/ece0302-Project4-KJR/tests/output00.png" "output00.png")
set_tests_properties(test00-compare PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;38;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
add_test(test01 "pathfinder" "/home/killian/ece0302-KR/ece0302-Project4-KJR/tests/maze01.png" "output01.png")
set_tests_properties(test01 PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;39;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
add_test(test01-compare "compare" "/home/killian/ece0302-KR/ece0302-Project4-KJR/tests/output01.png" "output01.png")
set_tests_properties(test01-compare PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;40;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
add_test(test02 "pathfinder" "/home/killian/ece0302-KR/ece0302-Project4-KJR/tests/maze02.png" "output02.png")
set_tests_properties(test02 PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;41;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
add_test(test02-compare "compare" "/home/killian/ece0302-KR/ece0302-Project4-KJR/tests/output02.png" "output02.png")
set_tests_properties(test02-compare PROPERTIES  _BACKTRACE_TRIPLES "/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;42;add_test;/home/killian/ece0302-KR/ece0302-Project4-KJR/CMakeLists.txt;0;")
subdirs("lib")
