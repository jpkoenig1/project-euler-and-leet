# Remove the build directory if it exists
if (Test-Path -Path "build") {
    Remove-Item -Recurse -Force "build"
}

# Create build directory and navigate into it
New-Item -ItemType Directory -Path "build" | Out-Null
Set-Location "build"

# Configure with CMake using Visual Studio 17 2022 generator
cmake -G "Visual Studio 17 2022" .. -DCMAKE_BUILD_TYPE=Release

# Build the project with 4 parallel jobs
cmake --build . --config Release --parallel 4

Set-Location "Release"

# .\leet_euler_framework.exe two_sum
