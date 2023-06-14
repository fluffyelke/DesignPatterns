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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Solid/DependencyInversionPrinciple/DependancyInversionPrinciple.o \
	${OBJECTDIR}/Solid/InterfaceSegregationPrinciple/InterfaceSegregationPrinciple.o \
	${OBJECTDIR}/Solid/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.o \
	${OBJECTDIR}/Solid/OpenClosedPrinciple/Product.o \
	${OBJECTDIR}/Solid/SingleResponsibilityPrinciple/Journal.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/designpatterns

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/designpatterns: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/designpatterns ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Solid/DependencyInversionPrinciple/DependancyInversionPrinciple.o: Solid/DependencyInversionPrinciple/DependancyInversionPrinciple.cpp
	${MKDIR} -p ${OBJECTDIR}/Solid/DependencyInversionPrinciple
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solid/DependencyInversionPrinciple/DependancyInversionPrinciple.o Solid/DependencyInversionPrinciple/DependancyInversionPrinciple.cpp

${OBJECTDIR}/Solid/InterfaceSegregationPrinciple/InterfaceSegregationPrinciple.o: Solid/InterfaceSegregationPrinciple/InterfaceSegregationPrinciple.cpp
	${MKDIR} -p ${OBJECTDIR}/Solid/InterfaceSegregationPrinciple
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solid/InterfaceSegregationPrinciple/InterfaceSegregationPrinciple.o Solid/InterfaceSegregationPrinciple/InterfaceSegregationPrinciple.cpp

${OBJECTDIR}/Solid/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.o: Solid/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.cpp
	${MKDIR} -p ${OBJECTDIR}/Solid/LiskovSubstitutionPrinciple
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solid/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.o Solid/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.cpp

${OBJECTDIR}/Solid/OpenClosedPrinciple/Product.o: Solid/OpenClosedPrinciple/Product.cpp
	${MKDIR} -p ${OBJECTDIR}/Solid/OpenClosedPrinciple
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solid/OpenClosedPrinciple/Product.o Solid/OpenClosedPrinciple/Product.cpp

${OBJECTDIR}/Solid/SingleResponsibilityPrinciple/Journal.o: Solid/SingleResponsibilityPrinciple/Journal.cpp
	${MKDIR} -p ${OBJECTDIR}/Solid/SingleResponsibilityPrinciple
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Solid/SingleResponsibilityPrinciple/Journal.o Solid/SingleResponsibilityPrinciple/Journal.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
