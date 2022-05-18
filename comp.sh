docker start arqui   
docker exec -it arqui make -C /root/Toolchain
docker exec -it arqui make -C /root/
docker stop arqui