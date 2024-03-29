add_rules("mode.debug", "mode.release")
set_warnings("all", "error")

add_requires("gtest", {system = true})

target("array")
    set_kind("static")
    add_files("src/array/*.cpp")

target("binarytree")
    set_kind("static")
    add_files("src/binarytree/*.cpp")

target("array")
    set_kind("static")
    add_files("src/array/*.cpp")


target("list")
    set_kind("static")
    add_files("src/list/*.cpp")

target("hash")
    set_kind("static")
    add_files("src/hash/*.cpp")

target("string")
    set_kind("static")
    add_files("src/string/*.cpp")

target("stack")
    set_kind("static")
    add_files("src/stack/*.cpp")

target("tree")
    set_kind("static")
    add_files("src/tree/*.cpp")


target("dp")
    set_kind("static")
    add_files("src/dp/*.cpp")


target("sword_to_offer")
    set_kind("static")
    add_files("src/sword_to_offer/*.cpp")


target("slidewindow")
    set_kind("static")
    add_files("src/slidewindow/*.cpp")

target("bipointer")
    set_kind("static")
    add_files("src/bipointer/*.cpp")
    
target("graph")
    set_kind("static")
    add_files("src/graph/*.cpp")

target("sort")
    set_kind("static")
    add_files("src/sort/*.cpp")    

target("main")
    set_kind("binary")
    add_files("src/main.cpp")
    add_deps("array")
    add_deps("binarytree")
    add_deps("list")
    add_deps("hash")
    add_deps("string")
    add_deps("stack")
    add_deps("tree")
    add_deps("dp")
    add_deps("slidewindow")
    add_deps("sword_to_offer")
    add_deps("bipointer")
    add_deps("graph")
    add_deps("sort")
    
    

target("test")
    set_kind("binary")
    add_files("src/test/main.cpp")
    add_packages("lpthread")
    add_packages("gtest")
    add_deps("string")
    add_deps("sort")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

