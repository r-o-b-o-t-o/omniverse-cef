-- Setup the extension.
local ext = get_current_extension_info()
project_ext(ext)

-- Link folders that should be packaged with the extension.
repo_build.prebuild_link {
    { "data", ext.target_dir.."/data" },
    { "docs", ext.target_dir.."/docs" },
}

-- Build the C++ plugin that will be loaded by the extension.
project_ext_plugin(ext, "r_o_b_o_t_o.cef")
local plugin_name = "r_o_b_o_t_o.cef"
add_files("source", "plugins/"..plugin_name)
add_files("include", "include")
defines { "ROBOTO_CEF_EXPORTS", "IMGUI_NVIDIA" }
exceptionhandling "On"
rtti "On"
includedirs {
    "include",
    "plugins/"..plugin_name,
    "%{target_deps}/boost-preprocessor",
    "%{target_deps}/imgui"
}
links { "carb", "%{extsbuild_dir}/omni.ui/bin/omni.ui", "%{extsbuild_dir}/omni.kit.renderer.imgui/bin/imgui" }

-- Build Python bindings that will be loaded by the extension.
project_ext_bindings {
    ext = ext,
    project_name = "r_o_b_o_t_o.cef.python",
    module = "_example_cpp_widget",
    src = "bindings/python/r_o_b_o_t_o.cef",
    target_subdir = "r_o_b_o_t_o/cef"
}
includedirs {
    "include",
    "bindings/python/r_o_b_o_t_o.cef",
    "%{target_deps}/boost-preprocessor",
    "%{target_deps}/imgui"
}
links { "r_o_b_o_t_o.cef", "%{extsbuild_dir}/omni.ui/bin/omni.ui" }
