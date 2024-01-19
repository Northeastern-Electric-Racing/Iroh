# Axon
> FreeRTOS Application to control the charging of the accumulator

## Setting up Docker Environment
> For initial installation, visit here: https://nerdocs.atlassian.net/wiki/spaces/NER/pages/108888108/Setting+Up+STM32+Dev+Env

```
# TLDR:
# Pull Container:
docker pull nwdepatie/ner-gcc-arm

# Run Container
# macOS: 
docker run --rm -it --privileged -v "$PWD:/home/app" nwdepatie/ner-gcc-arm:latest bash

# Windows:
docker run --rm -it --privileged -v "%cd%:/home/app" nwdepatie/ner-gcc-arm:latest bash
# or
docker run --rm -it --privileged -v "$(PWD):/home/app" nwdepatie/ner-gcc-arm:latest bash

# Linux:
sudo docker run --rm -it --privileged -v "$PWD:/home/app" nwdepatie/ner-gcc-arm:latest bash
```

## Container Tools and Utilities
> This container is packed with tools that can be utilized by developers to give them more insight into their developed software, we've used bash aliases to make the commands more compact for ease of use
```
## Tools / Utils

# to build project
make all
```
## Building Docker Container
>  Typically this isn't needed unless making local changes to Dockerfile, please default to the first method via pulling the docker container
```
# if need to rebuild image
sudo docker image prune -a
sudo docker build -f ./Dockerfile -t ner-gcc-arm .
```
