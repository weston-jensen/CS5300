# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wjensen/Coding_Projects/CS5300/CS5300

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wjensen/Coding_Projects/CS5300/CS5300

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/wjensen/Coding_Projects/CS5300/CS5300/CMakeFiles /home/wjensen/Coding_Projects/CS5300/CS5300/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/wjensen/Coding_Projects/CS5300/CS5300/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named cpsl

# Build rule for target.
cpsl: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cpsl
.PHONY : cpsl

# fast build rule for target.
cpsl/fast:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/build
.PHONY : cpsl/fast

Array_Type.o: Array_Type.cpp.o
.PHONY : Array_Type.o

# target to build an object file
Array_Type.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Array_Type.cpp.o
.PHONY : Array_Type.cpp.o

Array_Type.i: Array_Type.cpp.i
.PHONY : Array_Type.i

# target to preprocess a source file
Array_Type.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Array_Type.cpp.i
.PHONY : Array_Type.cpp.i

Array_Type.s: Array_Type.cpp.s
.PHONY : Array_Type.s

# target to generate assembly for a file
Array_Type.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Array_Type.cpp.s
.PHONY : Array_Type.cpp.s

Constant.o: Constant.cpp.o
.PHONY : Constant.o

# target to build an object file
Constant.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Constant.cpp.o
.PHONY : Constant.cpp.o

Constant.i: Constant.cpp.i
.PHONY : Constant.i

# target to preprocess a source file
Constant.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Constant.cpp.i
.PHONY : Constant.cpp.i

Constant.s: Constant.cpp.s
.PHONY : Constant.s

# target to generate assembly for a file
Constant.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Constant.cpp.s
.PHONY : Constant.cpp.s

Expressions.o: Expressions.cpp.o
.PHONY : Expressions.o

# target to build an object file
Expressions.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Expressions.cpp.o
.PHONY : Expressions.cpp.o

Expressions.i: Expressions.cpp.i
.PHONY : Expressions.i

# target to preprocess a source file
Expressions.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Expressions.cpp.i
.PHONY : Expressions.cpp.i

Expressions.s: Expressions.cpp.s
.PHONY : Expressions.s

# target to generate assembly for a file
Expressions.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Expressions.cpp.s
.PHONY : Expressions.cpp.s

Record.o: Record.cpp.o
.PHONY : Record.o

# target to build an object file
Record.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Record.cpp.o
.PHONY : Record.cpp.o

Record.i: Record.cpp.i
.PHONY : Record.i

# target to preprocess a source file
Record.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Record.cpp.i
.PHONY : Record.cpp.i

Record.s: Record.cpp.s
.PHONY : Record.s

# target to generate assembly for a file
Record.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Record.cpp.s
.PHONY : Record.cpp.s

TreeParser.o: TreeParser.cpp.o
.PHONY : TreeParser.o

# target to build an object file
TreeParser.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/TreeParser.cpp.o
.PHONY : TreeParser.cpp.o

TreeParser.i: TreeParser.cpp.i
.PHONY : TreeParser.i

# target to preprocess a source file
TreeParser.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/TreeParser.cpp.i
.PHONY : TreeParser.cpp.i

TreeParser.s: TreeParser.cpp.s
.PHONY : TreeParser.s

# target to generate assembly for a file
TreeParser.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/TreeParser.cpp.s
.PHONY : TreeParser.cpp.s

Type.o: Type.cpp.o
.PHONY : Type.o

# target to build an object file
Type.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Type.cpp.o
.PHONY : Type.cpp.o

Type.i: Type.cpp.i
.PHONY : Type.i

# target to preprocess a source file
Type.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Type.cpp.i
.PHONY : Type.cpp.i

Type.s: Type.cpp.s
.PHONY : Type.s

# target to generate assembly for a file
Type.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Type.cpp.s
.PHONY : Type.cpp.s

Var.o: Var.cpp.o
.PHONY : Var.o

# target to build an object file
Var.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Var.cpp.o
.PHONY : Var.cpp.o

Var.i: Var.cpp.i
.PHONY : Var.i

# target to preprocess a source file
Var.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Var.cpp.i
.PHONY : Var.cpp.i

Var.s: Var.cpp.s
.PHONY : Var.s

# target to generate assembly for a file
Var.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/Var.cpp.s
.PHONY : Var.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/main.cpp.s
.PHONY : main.cpp.s

parser.o: parser.cpp.o
.PHONY : parser.o

# target to build an object file
parser.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/parser.cpp.o
.PHONY : parser.cpp.o

parser.i: parser.cpp.i
.PHONY : parser.i

# target to preprocess a source file
parser.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/parser.cpp.i
.PHONY : parser.cpp.i

parser.s: parser.cpp.s
.PHONY : parser.s

# target to generate assembly for a file
parser.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/parser.cpp.s
.PHONY : parser.cpp.s

scanner.o: scanner.cpp.o
.PHONY : scanner.o

# target to build an object file
scanner.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/scanner.cpp.o
.PHONY : scanner.cpp.o

scanner.i: scanner.cpp.i
.PHONY : scanner.i

# target to preprocess a source file
scanner.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/scanner.cpp.i
.PHONY : scanner.cpp.i

scanner.s: scanner.cpp.s
.PHONY : scanner.s

# target to generate assembly for a file
scanner.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/scanner.cpp.s
.PHONY : scanner.cpp.s

symbol_table.o: symbol_table.cpp.o
.PHONY : symbol_table.o

# target to build an object file
symbol_table.cpp.o:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/symbol_table.cpp.o
.PHONY : symbol_table.cpp.o

symbol_table.i: symbol_table.cpp.i
.PHONY : symbol_table.i

# target to preprocess a source file
symbol_table.cpp.i:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/symbol_table.cpp.i
.PHONY : symbol_table.cpp.i

symbol_table.s: symbol_table.cpp.s
.PHONY : symbol_table.s

# target to generate assembly for a file
symbol_table.cpp.s:
	$(MAKE) -f CMakeFiles/cpsl.dir/build.make CMakeFiles/cpsl.dir/symbol_table.cpp.s
.PHONY : symbol_table.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... cpsl"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Array_Type.o"
	@echo "... Array_Type.i"
	@echo "... Array_Type.s"
	@echo "... Constant.o"
	@echo "... Constant.i"
	@echo "... Constant.s"
	@echo "... Expressions.o"
	@echo "... Expressions.i"
	@echo "... Expressions.s"
	@echo "... Record.o"
	@echo "... Record.i"
	@echo "... Record.s"
	@echo "... TreeParser.o"
	@echo "... TreeParser.i"
	@echo "... TreeParser.s"
	@echo "... Type.o"
	@echo "... Type.i"
	@echo "... Type.s"
	@echo "... Var.o"
	@echo "... Var.i"
	@echo "... Var.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... parser.o"
	@echo "... parser.i"
	@echo "... parser.s"
	@echo "... scanner.o"
	@echo "... scanner.i"
	@echo "... scanner.s"
	@echo "... symbol_table.o"
	@echo "... symbol_table.i"
	@echo "... symbol_table.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

