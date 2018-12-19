help([==[

Description
===========
Intel C/C++ and Fortran compilers, alongside Intel MKL.


More information
================
 - Homepage: http://software.intel.com/en-us/intel-cluster-toolkit-compiler/
]==])

whatis([==[Description: Intel C/C++ and Fortran compilers, alongside Intel MKL.]==])
whatis([==[Homepage: http://software.intel.com/en-us/intel-cluster-toolkit-compiler/]==])

local root = "/cvmfs/soft.computecanada.ca/easybuild/software/2017/Core/iimkl/2017.5"

conflict("iimkl")

if not isloaded("icc/.2017.5.239") or mode() == "unload" then
    load("icc/.2017.5.239")
end

if not isloaded("ifort/.2017.5.239") or mode() == "unload" then
    load("ifort/.2017.5.239")
end

if not isloaded("intel/2017.5") or mode() == "unload" then
    load("intel/2017.5")
end

if not isloaded("imkl/2017.4.239") or mode() == "unload" then
    load("imkl/2017.4.239")
end

setenv("EBROOTIIMKL", root)
setenv("EBVERSIONIIMKL", "2017.5")
setenv("EBDEVELIIMKL", pathJoin(root, "easybuild/Core-iimkl-.2017.5-easybuild-devel"))

-- Built with EasyBuild version 3.4.1-r23ea111b73714227b4f4004453f604c4a00b0e43
