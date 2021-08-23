from conans import ConanFile, CMake, tools
import os

class HelloConan(ConanFile):
    name = "ip_sort"
    
    def set_version(self):
        git = tools.Git(folder=self.recipe_folder)
        self.version = "%s" % (git.get_tag())
        
    license = "None"
    author = "Regina Sitkova"
    url = "https://github.com/regina-wakeup/first_task_1"
    description = "fist task for otus course"
    topics = ("<Put some tag here>", "<here>", "<and here>")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake"
    exports_sources = "src/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def build(self):
        os.environ["FIRST_TASK_VERSION"] = self.version
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()
        
        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["ip_converter"]
