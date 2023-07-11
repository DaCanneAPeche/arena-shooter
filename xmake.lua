add_rules("mode.debug", "mode.release")
add_requires("sfml")

target("arena-shooter")

    before_build(function (target)
        os.cp("$(projectdir)/data", "$(buildir)/$(host)/$(arch)/release/")
    end)

    set_kind("binary")
    add_files("Source/*.cpp", "Source/weapons/*.cpp", "Source/utils/*.cpp")
    add_includedirs("Header")
    add_languages("c++17")

    add_packages("sfml")
