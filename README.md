rift-virtual
============

Welcome! This is a project that aims to use the Oculus Rift to improve virtual conferencing. The idea is to have two people in distinctly seperate concrete spaces meet in a virtual space. Their connection to the virtual space should be so immersive that all the things that are lost in a phone call or video messaging are replicated by their connection to the virtual space. Pretty ambitious huh? The technologies used are the Oculus Rift, OpenSim, and CtrlAltStudio viewer, so you'll definitely need them once you're ready to get started!

Getting Started:
Using Visual Studio 2010, you will only need to change, in all configurations, the Additional Include Directories to [YOUR_SDK_LOCATION]/libOVR/Include and the Additional Library Directories to [YOUR_SDK_LOCATION]/libOVR/Lib/Win32. The libraries libovrd.lib and Winmm.lib should be added to debug configuration and libovr.lib and Winmm.lib to the release configuration (though they should already be added if you use our project properties)
