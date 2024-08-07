############################################
#
# Author; Michele Adduci
# Modified by Leandro Benedet Garcia
# Copyright 2019-Today. All rights reserved
#
# Powershell script to download and install automatically
# Visual C++ 2019 tools, CMake, Conan, WIX and Ninja
#
############################################

#######################################
#
# This script license is MIT as per this issue in Github:
# https://github.com/madduci/docker-msvc-cpp/issues/14
#
# If that link were to be broken, here's a link from wayback machine:
# http://web.archive.org/web/20240807123603/https://github.com/madduci/docker-msvc-cpp/issues/14
#
# The original script can be found here:
#
# https://github.com/madduci/docker-msvc-cpp/blob/master/vagrant/install_tools.ps1
#
#######################################

####################################
# Define Variables
####################################
$start_time = Get-Date
# Define where to download all the installers required
$working_directory = "$env:temp"
$packages_directory = "C:\Packages"


####################################
# Define Visual Studio information
####################################

# Checkout Visual Studio Components
# https://learn.microsoft.com/en-us/visualstudio/install/workload-component-id-vs-build-tools?view=vs-2022

# VS2022 Community Edition
$vs_installer_url = "https://c2rsetup.officeapps.live.com/c2r/downloadVS.aspx?sku=community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030"
$vs_installer_exe = "$working_directory\vs_community.exe"
# Defining where Visual Studio 2019 is installed
$vs_install_path = "C:\Program Files\Microsoft Visual Studio\2022\Community"
# Defining SDK version
$windows_sdk_version_major = "10"
$windows_sdk_version_minor = "20348"
# Defining where Windows SDK is installed
$windows_sdk_path = "C:\Program Files (x86)\Windows Kits\$windows_sdk_version_major"

# Define all the desired components
$module_core_build = "Microsoft.VisualStudio.Component.VC.CoreBuildTools"
$module_compilerx86 = "Microsoft.VisualStudio.Component.VC.Tools.x86.x64"
$module_vcredist ="Microsoft.VisualStudio.Component.VC.Redist.14.Latest"
$module_atl = "Microsoft.VisualStudio.Component.VC.ATL"
$module_atlfmfc = "Microsoft.VisualStudio.Component.VC.ATLMFC"
$module_sdk = "Microsoft.VisualStudio.Component.Windows10SDK.$windows_sdk_version_minor"
# Wait until the completion of the installer, do not restart the machine, don't show UI
$vs_silent_args = "--quiet --wait --norestart"
# Defining output path for archiving Visual C/C++ and Windows SDK
$vs_zip_output_path = "$packages_directory\VC2022"
$sdk_zip_output_path = "$packages_directory\SDK"

####################################
# Prepare Visual Studio Package
####################################

Write-Host "Downloading Visual Studio 2022 Community Edition"
Invoke-WebRequest -Uri "$vs_installer_url" -OutFile "$vs_installer_exe"

Write-Host "Installing C++ Development Environment"
Start-Process -FilePath "$vs_installer_exe" -Wait -ArgumentList "$vs_silent_args --add $module_vcredist --add $module_core_build --add $module_sdk --add $module_atlfmfc --add $module_atl --add $module_compilerx86";

####################################
# Cleanup
####################################

Write-Host "Removing downloaded installers/packages"
Remove-Item -Path "$vs_installer_exe" -Force

Write-Output "Setup completed. Time taken: $((Get-Date).Subtract($start_time).Minutes) minute(s)"
