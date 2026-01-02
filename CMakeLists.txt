cmake_minimum_required(VERSION 3.10)

# Tên dự án
project(MyRPG_Game)

set(CMAKE_CXX_STANDARD 17)

# 1. CẤU HÌNH RAYLIB
set(RAYLIB_PATH "C:/raylib/raylib")
include_directories(${RAYLIB_PATH}/src)

if(EXISTS "${RAYLIB_PATH}/lib")
    link_directories(${RAYLIB_PATH}/lib)
else()
    # Fallback nếu dùng bản source raw
    link_directories(${RAYLIB_PATH}/src)
endif()

# 2. TỰ ĐỘNG TÌM FILE CODE
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# 3. CẤU HÌNH INCLUDE NỘI BỘ
include_directories(src)

# 4. TẠO FILE CHẠY
add_executable(${PROJECT_NAME} ${SOURCES})

# 5. LINK THƯ VIỆN
target_link_libraries(${PROJECT_NAME} raylib winmm kernel32 opengl32 gdi32 user32)

# 6. TỰ ĐỘNG COPY THƯ MỤC ASSETS
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets)