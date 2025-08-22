FROM phusion/baseimage:18.04-1.0.0

RUN apt-get update && apt-get install -y \
    qt5-default \
    qt5-qmake \
    qtbase5-dev-tools \
    qtmultimedia5-dev \
	libxcb-xinerama0-dev \
	x11-apps \
	dbus-x11 \
    xquartz \
    xauth \
    git \
    build-essential
    
ENV DISPLAY=host.docker.internal:0

WORKDIR /root

RUN git clone https://github.com/DoctorW00/qtftp.git && \
    cd qtftp/src/qftp && \
    qmake && make && make install

RUN git clone https://github.com/DoctorW00/SFDLSaugerPro.git && \
    cd SFDLSaugerPro && \
    qmake && make

CMD ["/root/SFDLSaugerPro/SFDLSaugerPro"]
