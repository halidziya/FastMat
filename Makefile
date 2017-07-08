# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/halidziya/Desktop/HIGMM/FastMat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/halidziya/Desktop/HIGMM/FastMat

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/halidziya/Desktop/HIGMM/FastMat/CMakeFiles /home/halidziya/Desktop/HIGMM/FastMat/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/halidziya/Desktop/HIGMM/FastMat/CMakeFiles 0
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
# Target rules for targets named FastMat

# Build rule for target.
FastMat: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 FastMat
.PHONY : FastMat

# fast build rule for target.
FastMat/fast:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/build
.PHONY : FastMat/fast

Buffer.o: Buffer.cpp.o

.PHONY : Buffer.o

# target to build an object file
Buffer.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Buffer.cpp.o
.PHONY : Buffer.cpp.o

Buffer.i: Buffer.cpp.i

.PHONY : Buffer.i

# target to preprocess a source file
Buffer.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Buffer.cpp.i
.PHONY : Buffer.cpp.i

Buffer.s: Buffer.cpp.s

.PHONY : Buffer.s

# target to generate assembly for a file
Buffer.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Buffer.cpp.s
.PHONY : Buffer.cpp.s

Dirichlet.o: Dirichlet.cpp.o

.PHONY : Dirichlet.o

# target to build an object file
Dirichlet.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Dirichlet.cpp.o
.PHONY : Dirichlet.cpp.o

Dirichlet.i: Dirichlet.cpp.i

.PHONY : Dirichlet.i

# target to preprocess a source file
Dirichlet.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Dirichlet.cpp.i
.PHONY : Dirichlet.cpp.i

Dirichlet.s: Dirichlet.cpp.s

.PHONY : Dirichlet.s

# target to generate assembly for a file
Dirichlet.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Dirichlet.cpp.s
.PHONY : Dirichlet.cpp.s

Distribution.o: Distribution.cpp.o

.PHONY : Distribution.o

# target to build an object file
Distribution.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Distribution.cpp.o
.PHONY : Distribution.cpp.o

Distribution.i: Distribution.cpp.i

.PHONY : Distribution.i

# target to preprocess a source file
Distribution.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Distribution.cpp.i
.PHONY : Distribution.cpp.i

Distribution.s: Distribution.cpp.s

.PHONY : Distribution.s

# target to generate assembly for a file
Distribution.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Distribution.cpp.s
.PHONY : Distribution.cpp.s

IWishart.o: IWishart.cpp.o

.PHONY : IWishart.o

# target to build an object file
IWishart.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/IWishart.cpp.o
.PHONY : IWishart.cpp.o

IWishart.i: IWishart.cpp.i

.PHONY : IWishart.i

# target to preprocess a source file
IWishart.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/IWishart.cpp.i
.PHONY : IWishart.cpp.i

IWishart.s: IWishart.cpp.s

.PHONY : IWishart.s

# target to generate assembly for a file
IWishart.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/IWishart.cpp.s
.PHONY : IWishart.cpp.s

Matrix.o: Matrix.cpp.o

.PHONY : Matrix.o

# target to build an object file
Matrix.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Matrix.cpp.o
.PHONY : Matrix.cpp.o

Matrix.i: Matrix.cpp.i

.PHONY : Matrix.i

# target to preprocess a source file
Matrix.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Matrix.cpp.i
.PHONY : Matrix.cpp.i

Matrix.s: Matrix.cpp.s

.PHONY : Matrix.s

# target to generate assembly for a file
Matrix.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Matrix.cpp.s
.PHONY : Matrix.cpp.s

Normal.o: Normal.cpp.o

.PHONY : Normal.o

# target to build an object file
Normal.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Normal.cpp.o
.PHONY : Normal.cpp.o

Normal.i: Normal.cpp.i

.PHONY : Normal.i

# target to preprocess a source file
Normal.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Normal.cpp.i
.PHONY : Normal.cpp.i

Normal.s: Normal.cpp.s

.PHONY : Normal.s

# target to generate assembly for a file
Normal.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Normal.cpp.s
.PHONY : Normal.cpp.s

Stut.o: Stut.cpp.o

.PHONY : Stut.o

# target to build an object file
Stut.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Stut.cpp.o
.PHONY : Stut.cpp.o

Stut.i: Stut.cpp.i

.PHONY : Stut.i

# target to preprocess a source file
Stut.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Stut.cpp.i
.PHONY : Stut.cpp.i

Stut.s: Stut.cpp.s

.PHONY : Stut.s

# target to generate assembly for a file
Stut.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Stut.cpp.s
.PHONY : Stut.cpp.s

ThreadPool.o: ThreadPool.cpp.o

.PHONY : ThreadPool.o

# target to build an object file
ThreadPool.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/ThreadPool.cpp.o
.PHONY : ThreadPool.cpp.o

ThreadPool.i: ThreadPool.cpp.i

.PHONY : ThreadPool.i

# target to preprocess a source file
ThreadPool.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/ThreadPool.cpp.i
.PHONY : ThreadPool.cpp.i

ThreadPool.s: ThreadPool.cpp.s

.PHONY : ThreadPool.s

# target to generate assembly for a file
ThreadPool.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/ThreadPool.cpp.s
.PHONY : ThreadPool.cpp.s

Vector.o: Vector.cpp.o

.PHONY : Vector.o

# target to build an object file
Vector.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Vector.cpp.o
.PHONY : Vector.cpp.o

Vector.i: Vector.cpp.i

.PHONY : Vector.i

# target to preprocess a source file
Vector.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Vector.cpp.i
.PHONY : Vector.cpp.i

Vector.s: Vector.cpp.s

.PHONY : Vector.s

# target to generate assembly for a file
Vector.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Vector.cpp.s
.PHONY : Vector.cpp.s

Wishart.o: Wishart.cpp.o

.PHONY : Wishart.o

# target to build an object file
Wishart.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Wishart.cpp.o
.PHONY : Wishart.cpp.o

Wishart.i: Wishart.cpp.i

.PHONY : Wishart.i

# target to preprocess a source file
Wishart.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Wishart.cpp.i
.PHONY : Wishart.cpp.i

Wishart.s: Wishart.cpp.s

.PHONY : Wishart.s

# target to generate assembly for a file
Wishart.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/Wishart.cpp.s
.PHONY : Wishart.cpp.s

util.o: util.cpp.o

.PHONY : util.o

# target to build an object file
util.cpp.o:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/util.cpp.o
.PHONY : util.cpp.o

util.i: util.cpp.i

.PHONY : util.i

# target to preprocess a source file
util.cpp.i:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/util.cpp.i
.PHONY : util.cpp.i

util.s: util.cpp.s

.PHONY : util.s

# target to generate assembly for a file
util.cpp.s:
	$(MAKE) -f CMakeFiles/FastMat.dir/build.make CMakeFiles/FastMat.dir/util.cpp.s
.PHONY : util.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... FastMat"
	@echo "... Buffer.o"
	@echo "... Buffer.i"
	@echo "... Buffer.s"
	@echo "... Dirichlet.o"
	@echo "... Dirichlet.i"
	@echo "... Dirichlet.s"
	@echo "... Distribution.o"
	@echo "... Distribution.i"
	@echo "... Distribution.s"
	@echo "... IWishart.o"
	@echo "... IWishart.i"
	@echo "... IWishart.s"
	@echo "... Matrix.o"
	@echo "... Matrix.i"
	@echo "... Matrix.s"
	@echo "... Normal.o"
	@echo "... Normal.i"
	@echo "... Normal.s"
	@echo "... Stut.o"
	@echo "... Stut.i"
	@echo "... Stut.s"
	@echo "... ThreadPool.o"
	@echo "... ThreadPool.i"
	@echo "... ThreadPool.s"
	@echo "... Vector.o"
	@echo "... Vector.i"
	@echo "... Vector.s"
	@echo "... Wishart.o"
	@echo "... Wishart.i"
	@echo "... Wishart.s"
	@echo "... util.o"
	@echo "... util.i"
	@echo "... util.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
