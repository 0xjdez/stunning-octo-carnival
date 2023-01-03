import os

fd = os.open("foo", os.O_CREAT|os.O_RDWR|os.O_APPEND, 420)

os.write(fd, b"Hello world\n")
os.close(fd)