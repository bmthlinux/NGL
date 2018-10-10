cmake_minimum_required(VERSION 3.1)
find_package(PkgConfig)
find_package(glfw3 3.2 REQUIRED)


# Name of the project
set(PROJECT_NAME NGLTests)
project(${PROJECT_NAME})
#Bring the headers into the project (local ones)
include_directories(include $ENV{HOME}/NGL/include $ENV{HOME}/NGL/gl3w $ENV{HOME}/NGL/include/fmt )
# use C++ 14
set(CMAKE_CXX_STANDARD 14)
add_definitions(-DUSEGLM )
#the file(GLOB...) allows for wildcard additions of our src dir
set(SOURCES 
			${PROJECT_SOURCE_DIR}/main.cpp  
			${PROJECT_SOURCE_DIR}/MessageQueueTests.cpp  
			${PROJECT_SOURCE_DIR}/UtilTests.cpp           
			${PROJECT_SOURCE_DIR}/Vec4Tests.cpp
			${PROJECT_SOURCE_DIR}/Mat2Tests.cpp  
			${PROJECT_SOURCE_DIR}/NGLInitTests.cpp       
			${PROJECT_SOURCE_DIR}/VAOPrimitivesTests.cpp
			${PROJECT_SOURCE_DIR}/Mat3Tests.cpp  
			${PROJECT_SOURCE_DIR}/ObjTests.cpp           
			${PROJECT_SOURCE_DIR}/Vec2Tests.cpp
			${PROJECT_SOURCE_DIR}/Mat4Tests.cpp  
			${PROJECT_SOURCE_DIR}/ShaderLibTests.cpp     
			${PROJECT_SOURCE_DIR}/Vec3Tests.cpp
)


# see what platform we are on and set platform defines
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	message("Mac build")
	find_library(MACGL OpenGL)
	set ( PROJECT_LINK_LIBS -lNGL ${MACGL} -lgtest)

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set ( PROJECT_LINK_LIBS -lNGL -lGL -lpthread -lgtest)
endif()


#As were using Qt we need to run moc
# define that if you want to include the stanford data sets
# these are very big and make compilation time huge
add_definitions(-DADDLARGEMODELS)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

add_definitions(-O2) 


# now add NGL specific values
link_directories( $ENV{HOME}/NGL/lib )

# add exe and link libs that must be after the other defines
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS}  glfw)
