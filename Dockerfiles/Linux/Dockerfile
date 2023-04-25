FROM phusion/baseimage:18.04-1.0.0

RUN apt-get update && apt-get install -y \
    qt5-default \
    qt5-qmake \
    qtbase5-dev-tools \
    qtmultimedia5-dev \
    x11-apps \
    x11-utils \
    x11-xserver-utils \
    xauth \
    git \
    build-essential
    
ENV XDG_RUNTIME_DIR=/tmp

WORKDIR /root

RUN git clone https://github.com/DoctorW00/qtftp.git && \
    cd qtftp/src/qftp && \
    qmake && make && make install

RUN git clone https://github.com/DoctorW00/SFDLSaugerPro.git && \
    cd SFDLSaugerPro && \
    qmake && make

ENV DISPLAY=:0

CMD ["/root/SFDLSaugerPro/SFDLSaugerPro"]
