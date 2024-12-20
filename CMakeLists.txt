cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/blocks/Block.cpp
        src/blocks/Block.h
        src/Player.cpp
        src/Player.h
        src/items/Item.cpp
        src/items/Item.h
        src/MainMenu.h
        src/MainMenu.cpp
        src/blocks/FinishBlock.cpp
        src/blocks/FinishBlock.h
        src/Map.cpp
        src/Map.h
        src/Game.h
        src/Game.cpp
        src/blocks/DisappearingBlock.cpp
        src/blocks/DisappearingBlock.h
        src/blocks/SpeedBoostBlock.cpp
        src/blocks/SpeedBoostBlock.h
        src/blocks/SlowBlock.cpp
        src/blocks/SlowBlock.h
        src/blocks/KillBlock.cpp
        src/blocks/KillBlock.h
        src/CreditsScreen.h
        src/CreditsScreen.cpp
)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

file(COPY src/resources DESTINATION bin)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
elseif(UNIX)
#    target_link_libraries(main PRIVATE X11)
#    include_directories (/usr/include/freetype2)
endif()
