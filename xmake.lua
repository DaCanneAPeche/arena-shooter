add_rules("mode.debug", "mode.release")
add_requires("sfml")

target("arena-shooter")
    set_kind("binary")
    add_files("Source/*.cpp", "Source/weapons/*.cpp", "Tools/*.cpp")
    add_includedirs("Header", ".")
    add_languages("c++17")

    add_packages("sfml")
