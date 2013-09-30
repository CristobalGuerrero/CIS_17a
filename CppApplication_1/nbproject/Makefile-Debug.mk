#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=Cygwin-Windows
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/cygdrive/C\cygwin\bin C:/cygwin/bin/cyboost_programm_options-gcc-mt-1_33_1 C:/cygwin/bin/cygboost_regex-gcc-mt-1_33_1.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin-Windows/cppapplication_1.exe

dist/Debug/Cygwin-Windows/cppapplication_1.exe: /cygdrive/C/cygwin/bin/cyboost_programm_options-gcc-mt-1_33_1

dist/Debug/Cygwin-Windows/cppapplication_1.exe: /cygdrive/C/cygwin/bin/cygboost_regex-gcc-mt-1_33_1.dll

dist/Debug/Cygwin-Windows/cppapplication_1.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin-Windows
	${LINK.cc} -lboost_regex -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/cygdrive/C/cygwin/usr/include/boost-1_33_1/ -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin-Windows/cppapplication_1.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
