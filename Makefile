CFLAGS = -O0 -Wall
TARGET = cache_line

all:$(TARGET)

cache_line:cache_line.c
	$(CC) $(CFLAGS) -o $@ $^

run:$(TARGET)
	echo 3 | sudo tee /proc/sys/vm/drop_caches
	./cache_line

plot:run
	python ./draw_cacheline.py

clean:
	rm result.txt 
