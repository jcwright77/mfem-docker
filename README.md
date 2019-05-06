# mfem-docker
Set of dockerfiles to build a distributed mfem image with graphics. defaults to plasma-dev branch.

docker-opengl used to build new image based on Debian stretch with opengl support. MFEM image should be available with

    docker pull jcwright/mfem:latest

Build instructions:

    cd docker-opengl
    docker build -t jcwright/opengl:stretch .
    cd ..
    docker build -t jcwright/wxpython:stretch -f Dockerfile.wxpython-base .
    docker build -t jcwright/mfem -f Dockerfile.mfem .

Usage:

Launch image and open desktop

    docker run -d --name mfem -p 6080:6080 jcwright/mfem
    http://localhost:6080/ #or appropriate docker-machine ip address
    #in terminal in x11vnc
    cd src/mfem/miniapps/plasma 
    ./stix1d -no-vis -md 0.24 -ne 480 -dbcs '3 5' -s 3 -pc 3 -f 80e6  -B '0 0 5.4' -w J -slab '0 1 0 0.06 0.02' -num '2e20 2e20' -herm
     
 Include viz:
 
    glvis
    #open new terminal
    src/mfem/miniapps/plasma/stix1d -md 0.24 -ne 480 -dbcs '3 5' -s 3 -pc 3 -f 80e6  -B '0 0 5.4' -w J -slab '0 1 0 0.06 0.02' -num '2e20 2e20' -herm
      
 Visualize on host screen.
 
    #OSX instructions
    #on host terminal
    IP=$(ifconfig en0 | grep inet | awk '$1=="inet" {print $2}')
    docker run -it --rm --name mfem -e DISPLAY=$IP:0 -e XAUTHORITY=/.Xauthority --net host -v /tmp/.X11-unix:/tmp/.X11-unix -v ~/.Xauthority:/.Xauthority -p 6080:6080 jcwright/mfem
    glvis&
    src/mfem/miniapps/plasma/stix1d -md 0.24 -ne 480 -dbcs '3 5' -s 3 -pc 3 -f 80e6  -B '0 0 5.4' -w J -slab '0 1 0 0.06 0.02' -num '2e20 2e20' -herm
    #Windows instructions
    glvis &
    DISPLAY=192.xxx.xxx.xxx #value from docker-machine, or localhost depending on windows docker implementation
    docker run -it --rm --name mfem -e DISPLAY=$DISPLAY -p 6080:6080 jcwright/mfem
    #may need to authorize connection depending on x11 emulator set up.
      
      
